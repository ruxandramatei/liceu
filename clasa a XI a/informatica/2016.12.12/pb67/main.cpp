#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, m, st[100];
int nr;

void citire(){
  in>>n>>m;
}

void afisare(){
  bool ok;
  out<<"Solutia nr.:"<<nr<<'\n';
  for(int i=1;i<=n;i++){
    out<<"Ziua "<<i<<':';
    ok=false;
    for(int j=1;j<=m;j++)
      if(i==st[j]){
        out<<j<<',';
        ok=true;
      }
    if(ok==false)
      out<<'-';
    out<<'\n';
  }
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    st[k]=i;
    if(k<=m){
      if(k==m){
        nr++;
        afisare();
      }
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
