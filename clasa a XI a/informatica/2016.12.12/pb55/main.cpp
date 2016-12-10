#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int v[16], st[16], S, n;

void citire(){
  in>>n;
  for(int i=1;i<=n;i++)
    in>>v[i];
  in>>S;
}

void afisare(){
  for(int i=1;i<=n;i++)
    if(st[i]==0)
      out<<'+';
    else
      out<<'-';
  out<<'\n';
}

void bkt(int k){
  for(int i=0;i<=1;i++){
    st[k]=i;
    if(i==0)
      S-=v[k];
    else
      S+=v[k];
    if(S>=0 && k<=n){
      if(S==0 && k==n)
        afisare();
      else if(k<n)
        bkt(k+1);
    }
    if(i==0)
      S+=v[k];
    else
      S-=v[k];
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
