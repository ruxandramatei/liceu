#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb1.in");
ofstream out("pb1.txt");

int st[20], n, v[20];

void citire(){
  in>>n;
  for(int i = 1; i <= n; i++)
    in>>v[i];
}

void afisare(){
  for(int i = 1; i <= n; i++)
    out<<v[st[i]]<<' ';
  out<<"\n";
}

bool validare(int k){
  for(int i = 1; i < k; i++)
    if(st[i] == st[k])return false;
  return true;
}

bool solutie(int k){
  if(k == n)return true;
  return false;
}

void bktr(int k){
  for(int i = 1; i <= n; i++){
    st[k] = i;
    if(validare(k)){
      if(solutie(k))
        afisare();
      else
        bktr(k+1);
    }
  }
}

int main(){
  citire();
  bktr(1);
  return 0;
}
