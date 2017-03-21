#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

struct {

    int x, y;

}c[101];

int a[101][101], n, m;
int Dx[4]={-1,0,0,1};
int Dy[4]={0,-1,1,0};
int xPlec,yPlec, xFin, yFin;

void citire(){

    in>>n>>m;
    int x, y;
    in>>xPlec>>yPlec>>xFin>>yFin;
    for(int i=1;i<=n;i++)
    {
        in>>x>>y;
        a[x][y]=a[y][x]=1;
    }

}

bool inter(int x, int y){

    return (x>0 && x<m+1 && y>0 && y<n+1);

}

int lee(int xPlec, int yPlec){

    int p, u;
    p=u=1;
    c[1].x=xPlec;
    c[1].y=yPlec;
    a[xPlec][yPlec]=1;
    while(p<=u){
        xPlec=c[p].x;
        yPlec=c[p++].y;
        for(int i = 0; i<4;i++){
            int xVec = xPlec + Dx[i];
            int yVec = yPlec + Dy[i];
            if(inter(xVec,yVec) && a[xPlec][yPlec]==0){
                c[++u].x = xVec;
                c[u].y = yVec;
                a[xPlec][yPlec]==1;
                if(a[xFin][yFin]!=0)
                    return a[xFin][yFin];
            }
        }
    }
    return -1;

}

int main()
{
    citire();
    out<<lee(xPlec,yPlec);
    return 0;
}
