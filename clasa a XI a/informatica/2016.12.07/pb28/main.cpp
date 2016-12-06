#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[100], n;
int suma=0;

void citire(){
  in>>n;
}

void afisare(int k){
  for(int i=1;i<=k;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=9;i++){
    st[k]=i;
    suma+=st[k];
    if(suma<=5*n){
        if(suma==5*n && k==n)
          afisare(k);
        else if(k<n)
          bkt(k+1);
    }
    suma-=st[k];
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
