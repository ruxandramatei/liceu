#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101], n, viz[101];
int nr;

void citire(){

    in>>n;
    int x, y;
    while(in>>x>>y){
        a[x][y]=a[y][x]=1;
    }

}

void bf(int x,int pune){

    int p, u, c[101];
    p=u=1;
    c[1]=x;
    viz[x]=pune;

    while(p<=u){
        x=c[p++];
        for(int i=1;i<=n;i++)
            if(a[x][i]==1 && viz[i]==0){
                viz[i]=pune;
                c[++u]=i;
            }
    }

}

int rez[101];

int main()
{
    citire();
    for(int i=1;i<=n;i++){
        if(viz[i]==0){
            nr++;
            bf(i,nr);
        }
    }
    out<<"Muchiile adaugate sunt:";
    int nrrez=1;
    for(int i=1;i<=nr;i++){
        for(int j=1;j<=n && rez[i]==0;j++)
            if(viz[j]==i)
                rez[i]=j;
    }
    for(int i=2;i<=nr;i++)
        out<<"("<<rez[i-1]<<" ; "<<rez[i]<<" ) , ";
    out<<"\nNumarul de muchii ce trebuie adaugat este : "<<nr-1;
    return 0;
}
