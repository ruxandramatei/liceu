#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[20], n, a;

void citire(){
  in>>n>>a;
}

bool validare(int k){
  if(k==1 && st[k]!=n)
    return false;
  if(k==n && st[k]!=a+n)
    return false;
  for(int i = 1; i < k; i++){
    if(st[i] == st[k] ||st[i]>st[i+1])return false;
  }
  return true;
}

bool solutie(int k){
  if(st[k] == n+a)
    return true;
  return false;
}

void afisare(int k){
  for(int i=1; i<=k;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i = n; i <= n+a; i++){
    st[k] =  i;
    if(validare(k)){
      if(solutie(k)){
        afisare(k);
      }
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
