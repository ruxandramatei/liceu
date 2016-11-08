#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int st[20], n;

void citire(){
  in>>n;
}

void afisare(){
  for(int i = 1; i <= n; i++)
    out<<st[i];
  out<<"\n";
}

bool validare(int k){
  for(int i = 1; i < k; i++){
    if(st[i]%2 != st[i+1]%2)return false;
  }
  return true;
}

bool solutie(int k){
  if(k == n)return true;
  return false;
}

void bktr(int k){
  for(int i = 1; i <= 4; i++){
    st[k] = i;
    if(validare(k)){
      if(solutie(k))
        afisare();
      else
        bktr(k+1);
    }
  }
}

int main(){
  citire();
  bktr(1);
  return 0;
}
