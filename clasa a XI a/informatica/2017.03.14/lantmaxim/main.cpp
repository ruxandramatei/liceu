#include <iostream>
#include <fstream>

using namespace std;

ifstream in("lantmaxim.in");
ofstream out("lantmaxim.out");

int a[101][101], n, m;
int p, q;

void citire(){

    in>>n;
    in>>m;

    int x, y;
    for(int i=1;i<=m;i++){
        in>>x>>y;
        if(a[x][y]==0)
            a[x][y]=a[y][x]=1;
    }
    in>>p>>q;

}

int rez[101];
int maxim = 0;
int st[101] , c[101];

void copiere(int k){

    for(int i=1;i<=n;i++){
        rez[i]=st[i];
    }
    rez[0]=k;

}

void bkt(int k){

    for(int i=1;i<=n;i++)
    {
        st[k]=i;
        if(c[i]==0 && a[st[k]][st[k-1]]==1){
            c[i]=1;
            if(i==q && k>maxim){
                maxim = k;
                copiere(k);
            }
            else if(k<=(n*(n-1)/2))
                bkt(k+1);
            c[i]=0;
        }
    }

}

int main()
{
    citire();
    st[1]=p;
    c[p]=1;
    bkt(2);
    for(int i=1;i<=rez[0];i++)
        out<<rez[i]<<' ';
    return 0;
}
