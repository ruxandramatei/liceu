#include <iostream>
#include <fstream>

using namespace std;

ifstream in("permutari1.in");
ofstream out("permutari1.out");

int n;
int st[10];

void citire(){
  in>>n;
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
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i = n; i>= 1; i--){
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
