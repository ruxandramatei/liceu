#include <iostream>
#include <fstream>

using namespace std;

ifstream in("componenteconexe3.in");
ofstream out("componenteconexe3.out");

int a[101][101], n;
int viz[101];
int nr=0;
int maxim = 0;

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

    int indic = 0,temin=0;
    int sum;

    for(int i=1;i<=nr;i++){

        sum = 0;
        int tem=0;

        for(int j=1;j<=n;j++)
            if(viz[j]==i){
                sum++;
                if(tem==0)tem=j;
            }

        if(sum > maxim){
            maxim = sum;
            indic = i;
            temin = tem;
        }
        else if(sum == maxim && tem < temin)
        {
            indic = i;
            temin = tem;
        }
    }
     out<<temin<<' ';
     out<<maxim;
}

int main()
{
    citire();
    conex();
    return 0;
}
