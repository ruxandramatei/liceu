#include <iostream>
#include <fstream>

using namespace std;

int v[100], st[10], m, n;
int nr;
int maxim;

ifstream in("pb.in");
ofstream out("pb.txt");

void citire(){
  in>>m>>nr;
  while(m!=0){
    v[m%10]++;
    m/=10;
    n++;
  }
}

void nrNou(){
  int x=0;
  for(int i=1;i<=n-nr;i++)
    x=x*10+st[i];
  if(maxim<x)
    maxim = x;
}

void bkt(int k){
  for(int i=1;i<=9;i++){
    if(v[i]!=0){
      st[k]=i;
      v[i]--;
      if(k==n-nr)
        nrNou();
      else
        bkt(k+1);
      v[i]++;
    }
  }
}

int main(){
  citire();
  bkt(1);
  out<<maxim;
  return 0;
}
