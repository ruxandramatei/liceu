#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[10], n, nr[10];
bool v[10];

void citire(){
  in>>n;
  for(int i=1;i<=n;i++){
    in>>nr[i];
  }
}

int sol;

void afisare(){
  sol++;
  out<<"Solutia "<<sol<<':';
  for(int i=1;i<=n;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    if(v[i]==false){
      st[k]=i;
      v[i]=true;
      if((k>1 && st[k]%2 != st[k-1]%2)||k==1){
        if(k==n)
          afisare();
        else
          bkt(k+1);
      }
      v[i]=false;
    }
  }
}

int main(){
  citire();
  bkt(1);
  if(sol == 0)
    out<<"NU EXISTA SOLUTII!";
  return 0;
}
