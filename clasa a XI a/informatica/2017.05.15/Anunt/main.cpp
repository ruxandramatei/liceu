#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,m;

void citire(){
  in>>n>>m;
  for(int i=1;i<=m;i++){
    int x,y;
    in>>x>>y;
    a[x][y]=1;
  }
}

void bf(int x){
  int c[101],p,u,viz[101];
  c[0]=x;

  for(int i=0;i<=n;i++)
    viz[i]=0;

  c[1]=x;
  viz[x]=1;
  p=u=1;

  while(p<=u){
    x = c[p++];
    for(int i=1;i<=n;i++){
      if(viz[i]==0 && a[x][i]==1){
        c[++u]=i;
        viz[i]=1;
        viz[0]++;
      }
    }
  }
  if(viz[0]==n-1)
    out<<c[0]<<' ';
}

int main(){

  citire();
  for(int i=1;i<=n;i++){
    bf(i);
  }
  return 0;
}
