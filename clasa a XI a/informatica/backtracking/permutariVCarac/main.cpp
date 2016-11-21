#include <iostream>
#include <fstream>

using namespace std;

int n;
bool v[10];
int st[10];

ifstream in("pb.in");
ofstream out("pb.txt");

void citire(){
  in>>n;
}

void afisare(){
  for(int i=1;i<=n;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=n;i++){
    if(v[i]==false){
      st[k]=i;
      v[i]=true;
      if(k==n)
        afisare();
      else
        bkt(k+1);
      v[i]=false;
    }
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
