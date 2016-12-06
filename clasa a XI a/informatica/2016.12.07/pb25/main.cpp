#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int a[10][10], n;
int st[11];
int suma = 0, maxim = 0;

void citire(){
    in>>n;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        in>>a[i][j];
}

bool validare(int k){
  for(int i=1;i<k;i++)
    if(st[k]==st[i])
      return false;
  return true;
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    if(validare(k)){
      st[k]=i;
      suma+=a[k][i];
      out<<a[k][i]<<'\n';
      if(suma>maxim)
        maxim = suma;
      if(k<n)
        bkt(k+1);
      suma-=a[k][i];
    }
  }
}


int main(){
  citire();
  bkt(1);
  out<<maxim;
  return 0;
}
