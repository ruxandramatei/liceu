#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101], b[101][101], n, m;
int k

void citire(){

    in>>n>>m;
    for(int i=1;i<=m;i++){
        int x, y;
        in>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    in>>k;

}

int st[101];

void afisarelant(int x){

    for(int i=1;i<=)


}

void bf(int x){

    int c[101],d[101],p,u,temp;
    temp=x;
    for(int i=1;i<=n;i++){
        d[i]=-1;
    }
    p=u=1;
    d[x]=0;
    c[1]=x;
    while(p<=u){
        x=c[p++];
        for(int i=1;i<=n;i++)
            if(a[x][i]==1 && d[i]==-1){
                d[i]=d[x]+1;
                c[++u]=i;
            }
    }
    for(int i=1;i<=n;i++)
        b[i][temp]=d[i];

}

int main()
{
    citire();
    bf(k);
    for(int i=1;i<=n;i++){
        out<<i<<' '<<a[k][i]<<" : ";
        afisarelant(k,i);

    }
    return 0;
}
