#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n;
char v[2];
char st[10];

void citire(){
  in>>n;
}

bool validare(int k){
  if(k>1 && st[k-1]=='A' && st[k]=='A')
    return false;
  return true;
}

void afisare(){
  for(int i=1;i<=n;i++)
    out<<st[i];
  out<<'\n';
}

void bkt(int k){
  for(int i=0;i<=1;i++){
    st[k]=v[i];
    if(validare(k))
      if(k == n)
        afisare();
      else
        bkt(k+1);
  }
}

int main(){
  citire();
  v[0]='A';
  v[1]='M';
  bkt(1);
  return 0;
}
