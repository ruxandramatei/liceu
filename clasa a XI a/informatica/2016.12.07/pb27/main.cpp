#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[100], n;

void citire(){
  in>>n;
}

bool validare(int k){
  if(k==1)
    return (st[k]==1 || st[k]==2);
  if(k>1 && (abs(st[k-1]-st[k])==2||abs(st[k-1]-st[k])==3)){
    if(k==n)
      return (st[k]==8 || st[k]==9);
    return true;
  }
  return false;
}

void afisare(){
  for(int i=1;i<=n;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=2*n+1;i++){
    st[k]=i;
    if(validare(k)==true){
      if(k==n)
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
