#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[20], n, a, b;


void citire(){
  in>>n>>a>>b;
}

bool validare(int k){
  for(int i = 1; i < k; i++){
    if(st[i] == st[k])return false;
  }
  if(k>=2 && st[2] != a )return false;
  if(k>=n-1 && st[n-1]!=b)return false;
  if(st[n]==a)return false;
  return true;
}

bool solutie(int k){
  if(k == n)
    return true;
  return false;
}

void afisare(){
  for(int i=1; i<=n;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i = 1; i <= n; i++){
    st[k] =  i;
    if(validare(k)){
      if(solutie(k)){
        afisare();
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
