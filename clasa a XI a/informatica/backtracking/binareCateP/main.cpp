#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int n,nr1,p;
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
  for(int i = 0; i<=1;i++){
    st[k]=i;
    nr1+=i;
    if(nr1<=p){
      if(k==n)
        afisare();
      else
        bkt(k+1);
    }
    nr1-=i;
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
