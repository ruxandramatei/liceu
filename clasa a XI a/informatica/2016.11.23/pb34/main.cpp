#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[10];
char v[10];
int n, p, nr;

void citire(){
  in>>n>>p;
  for(int i=1;i<=p;i++){
    in>>v[i];
  }
}

void afisare(){
  for(int i=1;i<=n;i++){
    out<<v[st[i]];
  }
  out<<'\n';
}

bool validare(int k){
  if(k>1 && st[k-1]==st[k])
    return false;
  return true;
}

void bkt(int k){
  for(int i=1;i<=p;i++){
    st[k]=i;
    if(i==1)
      nr++;
    if(validare(k) && nr<=(n/2))
      if(k==n){
        if(nr==(n/2))
          afisare();
      }
      else
        bkt(k+1);
    if(i==1)nr--;
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
