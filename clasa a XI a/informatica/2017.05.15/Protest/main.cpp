#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[5001][5001],n,m,viz[5001],nr;

void citire(){
  in>>n>>m;
  for(int i=1;i<=m;i++){
    int x;
    in>>x;
    viz[x]=1;
  }
  for(int i=1;i<n;i++){
    int x,y;
    in>>x>>y;
    a[x][y]=1;
  }
}

void bf(){
  int p,u;
  p=u=1;
  int c[5001];
  c[1]=1;
  viz[1]=1;
  while(p<=u){
    int x = c[p++];
    for(int i=1;i<=n;i++){
      if(viz[i]==0 && a[x][i]==1){
          nr++;
          viz[i]=1;
          c[++u]=i;
      }
    }
  }
  out<<nr;
}

int main(){
  citire();
  bf();
  return 0;
}
