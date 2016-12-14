#include <iostream>
#include <fstream>

using namespace std;

int n, b, st[100];

ifstream in("pb.in");
ofstream out("pb.txt");

char r[100];
bool v[100];

void citire(){
  in>>n>>b;
  for(int i=1;i<=n;i++)
    in>>r[i];
}

void afisare(int k){
  for(int i=1;i<=k;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    if(v[i]==false){
      v[i]=true;
      st[k]=i;
      if(r[st[k]]=='b')
        b--;
      if(b>=0){
        if(b==0)
          afisare(k);
        else if(k<n)
          bkt(k+1);
      }
      if(r[st[k]]=='b')
        b++;
      v[i]=false;
    }
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
