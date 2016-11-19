#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, m, st[10];

void citire(){
  in>>n;
}

int maxim(int k){
  int max = st[1];
  for(int i = 2; i <= k; i++)
    if(st[i] > max)
      max = st[i];
  return max;
}

void afisare(){
  int M = maxim(n);
  for(int i = 1; i<=M; i++){
    out<<"{ ";
    for(int j = 1; j <= n; j++)
      if(st[j] == i)
        out<<j<<' ';
    out<<"}";
  }
  out<<'\n';
}

void bkt(int k){
  int M = maxim(k-1);
  for(int i = 1; i <= M+1; i++){
    st[k] = i;
    if(k == n)
      afisare();
    else
      bkt(k+1);
  }
}

int main(){
  citire();
  st[1]=1;
  bkt(2);
  return 0;
}
