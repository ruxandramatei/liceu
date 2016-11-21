// f : {1,2...n} --> {1,2...m}
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, m, st[10];

void citire(){
  in>>n>>m;
}

void afisare(){
  for(int i = 1; i<= n; i++){
    out<<"f("<<i<<")="<<st[i]<<' ';
  }
  out<<'\n';
}

int v[10],nr;

void bkt(int k){
  for(int i = 1; i<=m;i++){
    st[k]=i;
    if(v[i]==0){
      nr++;
    }
    v[i]++;
    if(k==n){
      if(nr == m)
        afisare();
    }
    else
      bkt(k+1);
    v[i]--;
    if(v[i]==0)nr--;
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
