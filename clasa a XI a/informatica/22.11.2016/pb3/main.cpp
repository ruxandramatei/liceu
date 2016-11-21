#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int n, v, st[10];

void citire(){
  in>>n>>v;
}

bool validare(int k){
  if(abs(st[k]-st[k-1])<v)
    return false;
  for(int i=1;i<k;i++)
    if(st[i]==st[k])
      return false;
  return true;
}

void afisare(){
  for(int i =1;i<=n;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    st[k]=i;
    if(validare(k)){
      if(k == n)
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
