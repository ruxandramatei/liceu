#include <iostream>
#include <fstream>

using namespace std;

ifstream in("componenteconexe2.in");
ofstream out("componenteconexe2.out");

int a[101][101], n;
int nr =0;
int m=0;
int viz[101];

void citire(){

    in>>n;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0){
            a[x][y]=a[y][x]=1;
            m++;
        }
    }

}

void bf(int x){

    nr++;
    int p,u;
    p=u=1;
    int c[101];
    c[1]=x;
    viz[x]=nr;

    while(p<=u){
        for(int i=1;i<=n;i++)
            if(viz[i]==0 && a[c[p]][i]==1)
            {
                viz[i]=nr;
                c[++u]=i;
            }
        p++;
    }
}

void conex(){

    for(int i=1;i<=n;i++)
        if(viz[i]==0)
        {
            bf(i);
        }
    if(m>=n)
        out<<m-n+nr;
    else
        out<<'0';
}


int main()
{
    citire();
    conex();
    return 0;
}
