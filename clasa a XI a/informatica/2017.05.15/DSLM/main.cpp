#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,p;

void citire(){
  in>>n>>p;
  int x,y;
  while(in>>x>>y){
    a[x][y]=1;
  }
}

int maxim,rez[10000],st[1001];

bool validare(int k){
  if(a[st[k-1]][st[k]]==1)
    return true;
  return false;
}

void copiere(int k){
  for(int i=1;i<=k;i++)
    rez[i]=st[i];
  rez[0]=k;
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    st[k]=i;
    if(validare(k)==true){
      a[st[k-1]][i]=-1;
      if(k>maxim){
        copiere(k);
        maxim=k;
      }
      if(k<(n*n-n))
        bkt(k+1);
      a[st[k-1]][i]=1;
    }
  }
}

int main(){
  citire();
  st[1]=p;
  bkt(2);
  for(int i=1;i<=rez[0];i++)
    out<<rez[i]<<' ';
  return 0;
}
