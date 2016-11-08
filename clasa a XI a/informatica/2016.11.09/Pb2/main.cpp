#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

char st[20];
int n;

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
    if(abs((int)st[i]-(int)st[i+1])!=1)
      return false;
    if(st[k]==st[i])
      return false;
  }
  return true;
}

bool solutie(int k){
  if(k == n)return true;
  return false;
}

void bktr(int k){
  for(char i = 'A'; i <= 'Z'; i++){
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
