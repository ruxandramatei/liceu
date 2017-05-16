#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int n,m, a[101][101];

void citire(){
  in>>n>>m;
  for(int i=1;i<=m;i++){
    int x,y;
    in>>x>>y;
    a[x][y]=1;
  }
}

void matrDrum(){
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        if(a[i][k]==1 && a[k][j]==1 && i!=k && j!=k){
          a[i][j]=1;
        }
}

int main(){
  citire();
  matrDrum();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      out<<a[i][j]<<' ';
    out<<"\n";
  }
  return 0;
}
