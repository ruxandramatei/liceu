#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,m;

void citire(){
  in>>n>>m;
  int x,y;
  for(int i=1;i<=m;i++){
    in>>x>>y;
    a[x][y]=1;
  }
}

void gradInter(){
  bool ok=false;
  for(int j=1;j<=n;j++){
    for(int i=1;i<=n;i++){
      a[0][j]+=a[i][j];
    }
    if(a[0][j]==0){
      ok=true;
      out<<j<<' ';
    }
  }
  if(ok==false)
    out<<"NU EXISTA";
}

int main(){
  citire();
  gradInter();
  return 0;
}
