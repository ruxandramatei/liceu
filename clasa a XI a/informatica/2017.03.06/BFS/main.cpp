#include <iostream>
#include <fstream>

using namespace std;

ifstream in("BFS.in");
ofstream out("BFS.out");

int a[101][101], n, m, x, p, u;
int coada[101];
bool viz[101];

void citire(){

    in>>n>>m>>x;
    int x1,y;
    for(int i=1;i<=m;i++){
        in>>x1>>y;
        a[x1][y]=a[y][x1]=1;
    }

}

void bfs(){

    coada[1]=x;
    viz[x]=true;
    p=1;
    u=1;
    out<<x<<' ';
    while(p<=u && u != n){

        for(int i=1;i<=n;i++)
        {
            if(a[i][coada[p]]==1 && viz[i]==false){
                coada[++u]=i;
                out<<i<<' ';
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
    return 0;
}
