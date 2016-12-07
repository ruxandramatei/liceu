#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, st[100];
char lit[2]={'A','M'};

void citire(){
  in>>n;
}

void afisare(){
  for(int i=1;i<=n;i++)
    out<<lit[st[i]];
  out<<'\n';
}
bool validare(int k){
  if(st[k]==0 && k>0 && st[k-1]==0)
    return false;
  return true;
}

void bkt(int k){
  for(int i=0;i<=1;i++){
    st[k]=i;
    if(validare(k))
      if(k==n)
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
