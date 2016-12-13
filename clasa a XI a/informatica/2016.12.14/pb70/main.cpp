#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

struct dictionar{
  int x, y;
}v[100];

int n, x, y, st[100];
bool t[100];

void citire(){
  in>>n>>x>>y;
  for(int i=1;i<=n;i++)
    in>>v[i].x>>v[i].y;
}

void afisare(int k){
  for(int i=1;i<=k;i++){
    out<<st[i]<<' ';
  }
  out<<'\n';
}

bool validare(int k){
  if(k==1 && v[st[1]].x!=x)
    return false;
  if(k>1 && v[st[k-1]].y!=v[st[k]].x)
    return false;
  return true;
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    if(t[i]==false){
      t[i]=true;
      st[k]=i;
      if(validare(k))
        if(v[st[k]].y==y)
          afisare(k);
        else if(k<n)
          bkt(k+1);
      t[i]=false;
    }
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
