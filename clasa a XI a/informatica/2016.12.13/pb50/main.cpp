#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int G, n, a, b, v[100];
int st[100];

void citire(){
  in>>n>>G>>a>>b;
  for(int i=1;i<=n;i++)
    in>>v[i];
}

void afisare(int k){
  for(int i=1;i<=k;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=st[k-1]+1; i<=n;i++){
    st[k]=i;
    G-=v[i];
    if(G>=0){
      if(k>=a && k<=b)
        afisare(k);
      else if(k<=n)
        bkt(k+1);
    }
    G+=v[i];
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
