#include <iostream>
#include <fstream>

using namespace std;

int n;
int st[100];
bool v[100];

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
      if((k==1 ||(k>1 && k<=n/2+1 && st[k]<st[k-1])||(k>n/2+1 && st[k]>st[k-1]))){
        if(k==n)
          afisare();
        if(k<n)bkt(k+1);
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
