#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,m;

void citire(){
  in>>n;
  int x,y;
  while(in>>x>>y)
    a[x][y]=1;
}

int st[101],viz[101];

void afisare()
{
  for(int i=1;i<=n;i++)
    out<<st[i]<<' ';
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    if(viz[i]==0 && a[st[k-1]][i]==1){
      st[k]=i;
      viz[i]=1;
      if(k==n)
        afisare();
      else if(k<n)
        bkt(k+1);
      viz[i]=0;
    }
  }
}

int main(){
  citire();
  st[1]=1;
  viz[1]=1;
  bkt(2);
  return 0;
}
