#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[10], n;

void citire(){
  in>>n;
}

bool validare(int k){
  for(int i = 1; i < k ; ++i){
    if(st[k]==st[i] ||abs(st[i]-st[k])==k-i)
      return false;
  }
  return true;
}

void afisare(){
  for(int i=1; i<=n;i++){
    for(int j=1;j<=n;j++){
      if(st[j]==i)
        out<<" D ";
      else
        out<<" 0 ";
    }
    out<<"\n";
  }
  out<<"\n\n";
}

void back(int k){
  for(int i = 1; i<=n; i++){
    st[k]=i;
    if(validare(k))
      if(k == n)
        afisare();
      else back(k+1);
  }
}

int main(){
  citire();
  back(1);
  return 0;
}
