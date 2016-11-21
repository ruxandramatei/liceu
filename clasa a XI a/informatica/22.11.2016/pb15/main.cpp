#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, p, nr1;
int st[10];

void citire(){
  in>>n>>p;
}

void afisare(){
  for(int i=1;i<=n;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=9;i++){
    st[k]=i;
    if(i == 1)
      nr1++;
    if(nr1<=p){
      if(k == n)
        afisare();
      else
        bkt(k+1);
    }
    if(i == 1)
      nr1--;
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
