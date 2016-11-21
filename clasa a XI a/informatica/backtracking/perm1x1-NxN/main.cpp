#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n;
int st[10],v[10];

void citire(){
  in>>n;
}

void afisare(){
  for(int i=1;i<=(n*(n+1)/2);i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    st[k]=i;
    v[i]++;
    if(v[i]<=i){
      if(k==(n*(n+1)/2))
        afisare();
      else
        bkt(k+1);
    }
    v[i]--;
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
