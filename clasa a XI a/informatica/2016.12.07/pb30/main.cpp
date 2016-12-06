#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, s;
int st[11];
int suma = 0;

void citire(){
    in>>n>>s;
}

bool validare(int k){
  for(int i=1;i<k;i++)
    if(st[k]==st[i])
      return false;
  return true;
}

void afisare(){
    for(int i=1;i<=n;i++)
      out<<st[i];
    out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=9;i++){
      st[k]=i;
      suma+=i;
      if(suma<=s && validare(k)){
        if(suma == s && k == n)
          afisare();
        else if(k<n)
          bkt(k+1);
      }
      suma-=i;
  }
}


int main(){
  citire();
  bkt(1);
  return 0;
}
