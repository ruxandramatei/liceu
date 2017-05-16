#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,m,vizGlob[101];

void citire(){
  in>>n>>m;
  for(int i=1;i<=m;i++){
    int x,y;
    in>>x>>y;
    a[x][y]=1;
  }
}

void bfDir(int x,int viz[101]){
  for(int i=1;i<=n;i++)
    viz[i]=0;
  int c[101],p,u;
  c[1]=x;
  p=u=1;
  viz[x]=1;
  while(p<=u){
    x = c[p++];
    for(int i=1;i<=n;i++){
      if(viz[i]==0 && vizGlob[i]==0&&  a[x][i]==1){
          viz[i]=1;
          c[++u]=i;
      }
    }
  }
}

void bfIndir(int x,int viz[101]){
  for(int i=1;i<=n;i++)
    viz[i]=0;
  int c[101],p,u;
  c[1]=x;
  p=u=1;
  viz[x]=1;
  while(p<=u){
    x = c[p++];
    for(int i=1;i<=n;i++){
      if(viz[i]==0 && vizGlob[i]==0 &&a[i][x]==1){
          viz[i]=1;
          c[++u]=i;
      }
    }
  }
}

void intersectie(int viz1[101],int viz2[101]){
  for(int i=1;i<=n;i++)
    if(viz1[i]==viz2[i]){
        vizGlob[i]=1;

    }
}

int main(){

  citire();
  int nr=0;
  for(int i=1;i<=n;i++){
    if(vizGlob[i]==0){
        int viz1[101],viz2[101];
        bfDir(i,viz1);
        bfIndir(i,viz2);
        intersectie(viz1,viz2);
        nr++;
    }
  }
  out<<nr;
  return 0;
}
