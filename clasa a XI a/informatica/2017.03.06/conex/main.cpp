#include <iostream>
#include <fstream>

using namespace std;

ifstream in("conex.in");
ofstream out("conex.out");

int a[101][101], n, m, x1, p, u;
int coada[101];
bool viz[101];

void citire(){

    in>>n;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0)
            a[y][x]=a[x][y]=1;
    }
    x1=1;

}

bool validare(){

    for(int i=1;i<=n;i++)
        if(viz[i]==false)
            return false;
    return true;

}

void bfs(){

    coada[1]=x1;
    viz[x1]=true;
    p=1;
    u=1;
    while(p<=u && u != n){

        for(int i=1;i<=n;i++)
        {
            if(a[i][coada[p]]==1 && viz[i]==false){
                coada[++u]=i;
                viz[i]=true;
            }
        }
        p++;
    }

}

int main()
{
    citire();
    bfs();
    if(validare()==false)
        out<<"NU";
    else
        out<<"DA";
    return 0;
}
