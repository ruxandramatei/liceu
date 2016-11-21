#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n;
int st[10];

void citire(){
  in>>n;
}

void afisare(){
  for(int i=1; i<=2*n+1;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

bool validare(int k){
  if(abs(st[k]-st[k-1])!=1)
    return false;
  return true;
}

void bkt(int k){
  for(int i=st[k-1]-1;i<=st[k-1]+1;i++){
    st[k]=i;
    if(validare(k) && st[k]>=0)
      if(k==2*n){
        st[k+1]=0;
        afisare();
      }
      else
        bkt(k+1);
  }
}

int main(){
  citire();
  st[1]=0;
  bkt(2);
  return 0;
}
