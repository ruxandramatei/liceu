#include <iostream>
#include <fstream>

using namespace std;

int n, st[100];
bool v[10];

ifstream in("pb.in");
ofstream out("pb.txt");

void citire(){
  in>>n;
}

void afisare(){
  for(int i=n;i>=1;i--){
    out<<st[i];
  }
  out<<'\n';
}

void bkt(int k){
  for(int i=1;i<=9;i++){
    if(v[i]==false){
      st[k]=i;
      v[i]=true;
      if(k==1 || (k>1 && k!=3 && st[k]<st[k-1] && st[k]%2+st[k-1]%2<=1)||(k==3 && st[k]<st[k-1] && st[k]%2+st[k-1]%2<=1 && st[k]==5)){
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
  return 0;
}
