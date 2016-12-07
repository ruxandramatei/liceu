#include <iostream>
#include <fstream>

using namespace std;

int st[100], a[100][100], n;
bool ok, v[100];

ifstream in("pb.in");
ofstream out("pb.txt");

void citire(){
  in>>n;
  int p,q;
  while(in>>p>>q){
    a[p][q]=a[q][p]=1;
  }
}

void afisare(){
  for(int i=1;i<=n;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

bool validare(int k){
  if(k>1 && a[st[k]][st[k-1]]==1)
    return false;
  if(k==n && a[st[n]][st[1]]==1)
    return false;
  return true;
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    if(v[i]==false){
      st[k]=i;
      v[i]=true;
      if(validare(k)){
        if(k==n){
          afisare();
          ok=true;
        }
        else{
          bkt(k+1);
        }
      }
      v[i]=false;
    }
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
