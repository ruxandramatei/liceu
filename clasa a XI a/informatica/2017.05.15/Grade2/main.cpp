#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[102][102],n,m;

void citire(){
  in>>n>>m;
  int x,y;
  for(int i=1;i<=m;i++){
      in>>x>>y;
      a[x][y]=1;
  }
}

void sumaLinCol(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      a[0][i]+=a[i][j];
      a[i][0]+=a[j][i];
    }
  }
}

void rezolvare(){
  int nre[101],cont=0;
  nre[0]=0;
  for(int i=1;i<=n;i++)
    if(a[0][i]==a[i][0])
      {
        nre[0]++;
        nre[++cont]=i;
      }
    out<<nre[0]<<'\n';
    for(int i=1;i<=nre[0];i++)
      out<<nre[i]<<' ';
}

int main(){

  citire();
  sumaLinCol();
  rezolvare();

  return 0;
}
