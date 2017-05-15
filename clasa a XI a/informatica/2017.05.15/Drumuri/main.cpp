#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,m,plec,rez[101],viz[101];

void citire(){
  in>>n>>plec>>m;
  int x,y;
  for(int i=1;i<=m;i++){
    in>>x>>y;
    a[x][y]=1;
  }
}

void bf(){
  int c[101],p,u;
  p=u=1;
  c[1]=plec;
  viz[plec]=1;
  while(p<=u){
    int x=c[p++];
    for(int i=1;i<=n;i++){
      if(viz[i]==0 && a[x][i]==1){
        viz[i]=viz[x]+1;
        if((viz[i]-1)%2==0){
          rez[++rez[0]]=i;
        }
        c[++u]=i;
      }
    }
  }
  out<<rez[0]<<'\n';
  for(int i=1;i<rez[0];i++)
    for(int j=i+1;j<=rez[0];j++)
      if(rez[i]>rez[j]){
        int aux = rez[i];
        rez[i]=rez[j];
        rez[j]=aux;
      }
  for(int i=1;i<=rez[0];i++){
    out<<rez[i]<<' ';
  }
}


int main(){
  citire();
  bf();
  return 0;
}
