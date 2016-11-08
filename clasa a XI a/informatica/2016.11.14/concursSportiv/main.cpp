#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

struct ele{
  char s[4];
}v[100];

int n, m;
int st[100];

void citire(){
  in>>n>>m;
  for(int i = 1; i <= n; i++)
    in>>v[i].s;
}

bool validare(int k){

  if(k > 1 && strcmp(v[st[k]].s,v[st[k-1]].s)==0)return false;

  for(int i = 1; i < k; i++){
    if(st[i] > st[i+1])
      return false;
    if(st[i]==st[k])return false;
  }
  return true;

}

bool solutie(int k){
  if(k==m)
    return true;
  return false;
}

void afisare(){
  for(int i = 1; i <= m; i++)
    out<<st[i]<<v[st[i]].s<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i = 1; i <= n; i++){
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
