#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[10],n;
int nr0,nr1;

void citire(){
  in>>n;
}

void afisare(){
  for(int i=1;i<=n;i++){
    if(st[i]==0)
      out<<" ( ";
    else
      out<<" ) ";
  }
  out<<'\n';
}

void bkt(int k){
  for(int i=0;i<=1;i++){
    st[k]=i;
    (i==0)?(nr0++):(nr1++);
    if(nr0>=nr1 && nr0<=n/2){
      if(k==n)
        afisare();
      else
        bkt(k+1);
    }
    (i==0)?(nr0--):(nr1++);
  }
}
int main(){
  citire();
  bkt(1);
  return 0;
}
