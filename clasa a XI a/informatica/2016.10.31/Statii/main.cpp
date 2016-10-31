#include <iostream>
#include <fstream>

using namespace std;

ifstream in("statii.in");
ofstream out("statii.txt");

struct nod{
  int info,poz;
};

nod  v[100],r[100];
int n,x,k;

void citire(){
  in>>n;
  n--;
  in>>x;
  for(int i=1;i<=n;i++){
    in>>v[i].info;
    v[i].poz = i;
  }
}

void greedy(){
  int drum_plus = 0;
  r[1]=v[1];
  k=1;
  for(int i=2;i<=n;i++){
      if(drum_plus+v[i-1].info>=x){
        r[++k]=v[i];
        drum_plus = 0;
      }
      else{
        drum_plus+=v[i-1].info;
      }
  }
  out<<k<<'\n';
  for(int i=1;i<=k;i++)
    out<<r[i].poz<<' ';
}

int main(){
  citire();
  greedy();
  return 0;
}
