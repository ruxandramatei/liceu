#include <iostream>
#include <fstream>

using namespace std;

ifstream in("lantminim.in");
ofstream out("lantminim.out");

int a[101][101], n, p, q;
int st[101], c[101];
int rez[101];
int minim = 4951;

void citire(){

    in>>n>>p>>q;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0){
            a[x][y]=a[y][x]=1;
        }

    }
    st[1]=p;
    c[p]=1;

}

bool eLant(int k){

    if(a[st[k]][st[k-1]]==0)
        return false;
    return true;
}

void copiere(int k){
    rez[0]=k;
    for(int i=1;i<=k;i++)
        rez[i]=st[i];

}

void afisare(){

    out<<rez[0]<<'\n';

    for(int i=1;i<=rez[0];i++)
        out<<rez[i]<<' ';

}

void bkt(int k){

    for(int i=1;i<=n;i++)
    {
        if(c[i]==0){
            c[i]=1;
            st[k]=i;
            if(eLant(k)){
                if(k < minim && st[k]==q){
                    copiere(k);
                    minim = k;
                }
                else if(k < n && k <minim)
                    bkt(k+1);
            }
            c[i]=0;
        }
    }
}

int main()
{
    citire();
    bkt(2);
    afisare();
    return 0;
}
