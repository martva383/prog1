#include<iostream>
#include<new>
#include<vector>
#include<math.h>

using namespace std;
struct elem
{
    int adat;
    elem* bal;
    elem* jobb;
};

int input (vector<int> &t)
{
    cout<<"input adatok:\n";
    int k=0;
    if(t.size()<=1000)
    {
        for (int i=0; i<t.size() ; i++)
        {
            k++;
            cout<<t[i];
            if(k%60==0)
                cout<<endl;
        }
        cout<<endl;
    }
    else

        cout<<"beolvasott adatok szama meghaladja az ezret\n";


}

int elemszam (elem * gyoker)
{
    if (gyoker==NULL)
        return 0;
    if(gyoker->adat==-1)
        return elemszam(gyoker->bal)+elemszam(gyoker->jobb);
    return elemszam(gyoker->bal)+1+elemszam(gyoker->jobb);
}


int levelek(elem * gyoker)
{
    if (gyoker==NULL)
        return 0;
    if (gyoker->bal==gyoker->jobb)
        return levelek(gyoker->bal)+levelek(gyoker->jobb)+1;

    return levelek(gyoker->bal)+levelek(gyoker->jobb);


}
void kiir( vector<int> &v, int x)
{
    for (int i=0; i<x ; i++)
        cout<<v[i]<<" ";

    cout<<endl;

}


void utak(elem * gyoker, vector<int> &hossz, vector<int> &v)
{
    if (gyoker!=0)
    {
        if(gyoker->adat!=-1)
            v.push_back(gyoker->adat);
        if(gyoker->bal==gyoker->jobb)
        {
            kiir(v, v.size());

            hossz.push_back(v.size());
        }
        utak(gyoker->bal, hossz, v);
        utak(gyoker->jobb, hossz, v);
        v.pop_back();

    }
}

int maxh(vector<int> &v)
{
    int maxi= 0;
    for (int i=0; i<v.size(); i++ )
        if(maxi<v[i])
            maxi=v[i];
    return maxi;

}
double ossz(vector<int> &v)
{
    double ossz=0;
    for (int i=0;  i<v.size(); i++)
        ossz+=v[i];
    return ossz;
}


double szoras(vector<int> &v, double x)
{
    double osszeg=0;
    for (int i=0; i<v.size(); i++)
        osszeg+=pow(v[i]-x,2);

    return sqrt(osszeg/v.size() );
}


int main ()
{
    elem gy;
    gy.adat=-1;
    gy.bal=gy.jobb=0;
    elem *fa=NULL;
    fa=&gy;
    elem * p=fa;
    vector<int> t;
    int x;
    while (cin>>x)
    {

        if (x==0)
        {
            if(p->bal==NULL)
            {
                elem *uj= new elem;
                uj->adat=0;
                uj->bal=uj->jobb=0;
                p->bal=uj;
                p=fa;
            }
            else
                p=p->bal;
}
        else
        {
            if(x==1)
            {
                if(p->jobb==NULL)
                {
                    elem * uj= new elem;
                    uj->adat=1;
                    uj->bal=uj->jobb=0;
                    p->jobb=uj;
                    p=fa;

                }
                else
                    p=p->jobb;
            }
            else
            {
                cerr<<"A bemenet nem 0 vagy 1 volt!";
                return 0;
            }

        }
        t.push_back(x);

    }


 input(t);
    vector<int> hossz;
    vector<int> v;
    int elemdb=elemszam(fa);
    cout<<"Elemek szama: "<<elemdb<<endl;
    double leveldb=levelek(fa);
    cout<<"Levelek szama: "<<leveldb<<endl;
    cout<<"A fa agai:\n";
    utak(fa, hossz, v);

    cout<<"Leghosszabb ut: "<<maxh(hossz)<<endl;
    double atlag;
    atlag=ossz(hossz)/ leveldb;
    cout<<"Agak atlag hossza: "<<atlag<<endl;
    cout<<"Atlag hossz szoras: "<<szoras(hossz, atlag)<<endl;

