#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, s, v[100], q[100], st[10];
int suma;

void citire(){
  in>>s>>n;
  for(int i = 1; i<=n;i++){
    in>>v[i];
    q[i]=s/v[i];
  }
}

bool validare(int k){
  suma = 0;
  for(int i = 1; i<=k;i++){
    suma+=st[i]*v[i];
  }
  if(suma<=s && k<=n)
    return true;
  return false;
}

void afisare(int k){
  out<<"S = ";
  for(int i =1; i<=k;i++){
    out<<st[i]<<" * "<<v[i]<<" + ";
  }
  out<<"\n";
}

void bkt(int k){
  for(int i = 1; i<= q[k];i++){
      st[k]=i;
      if(validare(k))
        if(suma == s)
          afisare(k);
        else
          bkt(k+1);
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
