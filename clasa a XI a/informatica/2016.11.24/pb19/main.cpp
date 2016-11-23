#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, m, st[100];

void citire(){
  in>>n>>m;
}

void afisare(int k, int t){
  out<<"cutia "<<t<<" : ";
  for(int i=1;i<=k;i++){
    out<<st[i]<<',';
  }
  out<<'\n';
}

void bkt(int k, int t){
  for(int i=st[k-1]+1;i<=n;i++){
    st[k]=i;
    afisare(k,t);
    if(k<n)
      bkt(k+1,t);
  }
}

int main(){
  citire();
  for(int i=1;i<=m;i++){
    st[0]=0;
    bkt(1,i);
    out<<"cutia "<<i<<" : -\n";
  }
  return 0;
}
