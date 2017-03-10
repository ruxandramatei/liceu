#include <iostream>
#include <fstream>

using namespace std;

ifstream in("lungimeminima.in");
ofstream out("lungimeminima.out");

int a[101][101],n,p,l;
int c[101];
int  viz[101];
int nr=0;

void citire(){

    in>>n>>p>>l;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0)
            a[x][y]=a[y][x]=1;
    }

}

void bf(){

    int pr,ul;
    pr=ul=1;
    c[1]=p;

    for(int i=1;i<=n;i++)
        viz[i]=-1;

    viz[p]=0;
    while(pr<=ul){
        for(int i=1;i<=n;i++)
        {
           if(viz[i]==-1 && a[c[pr]][i]==1){
                viz[i]=viz[c[pr]]+1;
                if(viz[i]==l)
                    nr++;
                c[++ul]=i;
           }
        }
        pr++;
    }
    out<<nr<<'\n';
    for(int i=1;i<=n;i++)
        if(viz[i]==l)
            out<<i<<' ';

}

int main()
{
    citire();
    bf();
    return 0;
}
