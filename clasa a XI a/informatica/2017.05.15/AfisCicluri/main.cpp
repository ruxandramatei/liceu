#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,m;

void citire(){
  in>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int x,y;
    in>>x>>y;
    a[x][y]=1;
  }
}

int st[101],viz[101];

void afisare(){
  for(int i=1;i<4;i++){
    out<<st[i]<<' ';
  }
  out<<'\n';
}

bool validare(int k){
  if(k==1 ||(a[st[k]][st[k-1]]+a[st[k-1]][st[k]]>=1))
    return true;
  return false;
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    st[k]=i;
    if(viz[i]==0 && validare(k)){
      viz[i]=1;
      if(k<3)
        bkt(k+1);
      else if(k==3 && (a[st[k]][st[1]]+a[st[1]][st[k]]>=1))
        afisare();
      viz[i]=0;
    }
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
