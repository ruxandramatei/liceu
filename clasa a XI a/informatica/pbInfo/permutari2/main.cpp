#include <iostream>
#include <fstream>

using namespace std;

ifstream in("permutari2.in");
ofstream out("permutari2.out");

int n, v[10];
int st[10];

void citire(){
  in>>n;
  for(int i=1;i<=n;i++)
    in>>v[i];
  for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
      if(v[i]>v[j]){
        v[0]=v[i];
        v[i]=v[j];
        v[j]=v[0];
      }
}


bool validare(int k){
  for(int i = 1; i < k; i++)
      if(st[i] == st[k])
        return false;
  return true;
}

bool solutie(int k){
  if(k == n)
    return true;
  return false;
}

void afisare(){
  for(int i = 1; i <= n; i++)
    out<<v[st[i]]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i = 1; i<= n; i++){
      st[k]=i;
      if(validare(k)){
        if(solutie(k))
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
