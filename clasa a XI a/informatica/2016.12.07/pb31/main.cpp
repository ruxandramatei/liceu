#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, st[100];

void citire(){
  in>>n;
}

void afisare(int k){
  for(int i=1;i<=k;i++)
    out<<st[i];
  out<<"\n";
}

void bkt(int k){
  for(int i=st[k-1]+2;i<=8;i+=2){
      st[k]=i;
      afisare(k);
      if(k<n)bkt(k+1);
  }
}

int main(){
  citire();
  st[0]=0;
  bkt(1);
  return 0;
}
