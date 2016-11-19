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

bool validare(int k){
  for(int i = 1; i < k; i++)
    if(st[i] == st[k])
      return false;
  return true;
}

void afisare(){
  for(int i = 1; i <= n; i++)
    out<<"f("<<i<<") = "<<st[i]<<" ; ";
  out<<'\n';
}

void bkt(int k){
  for(int i = 1; i<=m; i++){
    st[k] = i;
    if(validare(k))
      if(k == n)
        afisare();
      else
        bkt(k+1);
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
