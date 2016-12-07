#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, p;
char lit[100];
int st[100], nr1=0;

void citire(){
  in>>n>>p;
  for(int i=1;i<=p;i++)
    in>>lit[i];
}

void afisare(){
  for(int i=1;i<=n;i++)
    out<<lit[st[i]];
  out<<'\n';
}

bool validare(int k){
  if(st[k-1]==st[k])
    return false;
  return true;
}

void bkt(int k){
  for(int i=1;i<=p;i++){
    st[k]==i;
    if(i==1)
      nr1++;
    if(validare(k) && nr1<=(n/2)){
        if(k==n && nr1==(n/2))
          afisare();
        else if(k<n)
          bkt(k+1);
    }
    if(i==1)
      nr1--;
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
