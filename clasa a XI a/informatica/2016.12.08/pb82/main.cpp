#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, m, st[100];

void citire(){
    in>>m>>n;
}

void afisare(){
  for(int i=1;i<=m+n; i++){
    if(st[i]==0)
      out<<"-leu";
    else
      out<<"-tigru";
  }
  out<<'\n';
}

void bkt(int k){
  for(int i=0;i<=1;i++){
    st[k]=i;
    if((st[k-1]!=st[k]&& k>1)||k==1){
      if(k==n+m)
        afisare();
      else
        bkt(k+1);
    }
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
