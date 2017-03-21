#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101], n;

void citire(){

    in>>n;
    int x, y;
    while(in>>x>>y){
        a[x][y]=a[y][x]=1;
    }

}

int viz[101];

bool bf(int x){

    int p, u, c[101];
    p=u=1;
    c[1]=x;
    viz[x]=1;

    while(p<=u){
        x=c[p++];
        for(int i=1;i<=n;i++)
            if(a[i][x]==1 && viz[i]==0){
                viz[i]=1;
                c[++u]=i;
            }
    }
    for(int i=1;i<=n;i++)
        if(viz[i]==0)
            return false;
    return true;

}

int main()
{
    citire();
    if(bf(1)==true)
        out<<"Este conex!";
    else
        out<<"Naspa!Nu e!";

    return 0;
}
