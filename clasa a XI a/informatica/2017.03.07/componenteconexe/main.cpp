#include <iostream>
#include <fstream>

using namespace std;

ifstream in("componenteconexe.in");
ofstream out("componenteconexe.out");

int a[101][101], n;
int viz[101];
int nr=0;

void citire(){

    in>>n;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0)
            a[x][y]=a[y][x]=1;
    }

}

void bf(int x){

    nr++;
    int p, u, c[101];
    p=u=1;
    c[1]=x;
    viz[x]=nr;

    while(p<=u){
        for(int i=1;i<=n;i++)
            if(a[c[p]][i]==1 && viz[i]==0)
            {
                viz[i]=nr;
                c[++u]=i;
            }
        p++;
    }

}

void conex(){

    for(int i=1;i<=n;i++){
        if(viz[i]==0){
            bf(i);
        }
    }
    out<<nr<<'\n';
    for(int i=1;i<=nr;i++){
        for(int j=1;j<=n;j++)
            if(viz[j]==i)
                out<<j<<' ';
        out<<'\n';
    }

}

int main()
{
    citire();
    conex();
    return 0;
}
