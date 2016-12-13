#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

struct traseu{
  int x,y;
};

int Dx[5]={-1, 0,1,0};
int Dy[5]={ 0,1,0,-1};

int xs, ys, xc, yc, n, m;
int a[20][20];

traseu st[4001];

void citire(){
  in>>n>>m;
  in>>xs>>ys>>xc>>yc;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      in>>a[i][j];
}

void afisare(int k){
  for(int i=1;i<=k;i++)
    out<<"("<<st[i].x<<";"<<st[i].y<<")\n";
  out<<'\n';
}

bool exist(int x, int y){
  return x>=1 && y<=m && x<=n&& y>=1;
}

void bkt(int x, int y, int k){
  a[x][y]=1;
  st[k].x=x;
  st[k].y=y;
  if(x==xc && y==yc)
    afisare(k);
  else{
    int xv, yv;
    for(int i=0;i<=3;i++){
      xv = x+Dx[i];
      yv = y+Dy[i];
      if(exist(xv, yv) && a[xv][yv]==0)
        bkt(xv,yv,k+1);
      }
  }
  a[x][y]=0;
}

int main(){
  citire();
  bkt(xs,ys,1);
  return 0;
}
