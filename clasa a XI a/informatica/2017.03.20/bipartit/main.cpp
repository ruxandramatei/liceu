#include <iostream>
#include <fstream>

using namespace std;

ifstream in("bipartit1mare.in");
ofstream out("bipartit1mare.out");

int a[101][101], n, m;
int viz[101], c[101];

void citire(){

    in>>n>>m;
    int x, y;
    for(int i=1;i<=m;i++){
        in>>x>>y;
        a[x][y]=a[y][x]=1;
    }

}

bool bipartit(int x){

    int p, u;
    p=u=1;

    c[1]=x;
    viz[x]=1;

    while(p<=u){
        x=c[p++];
        for(int i=1;i<=n;i++)
        if(a[x][i]==1){
            if(viz[i]==0){
                viz[i]=3-viz[x];
                c[++u]=i;
            }
            else if(viz[i]==viz[x])
                return false;
        }
    }
    return true;

}

int main()
{
    citire();
    if(bipartit(1)==true){
        out<<"DA\n";
        for(int i=1;i<=n;i++)
            if(viz[i]==1)
                out<<i<<' ';
        out<<'\n';
        for(int i=1;i<=n;i++)
            if(viz[i]==2)
                out<<i<<' ';
    }
    else
        out<<"NU";

    return 0;
}
