#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

ifstream in("pb5.in");
ofstream out("pb5.txt");

int st[9];
char s[10];
int nrTot;
int n;
void citire(){
  in>>s;
  n = strlen(s)-1;
}

void afisare(){
  for(int i = 0; i <= n; i++)
    out<<s[st[i]];
  out<<"\n";
}


bool validare(int k){
  for(int i = 0; i < k; i++){
    if(st[i] == st[k] )
      return false;
    if(strchr("aeiouAEIOU",s[st[i]]) && strchr("aeiouAEIOU",s[st[i+1]]))
      return false;
  }
  return true;
}

bool solutie(int k){
  if(k == n)return true;
  return false;
}

void bktr(int k){
  for(int i = 0; i <= n; i++){
    st[k] = i;
    if(validare(k)){
      if(solutie(k)){
          afisare();
          nrTot++;
      }
      else
        bktr(k+1);
    }
  }
}

int main(){
  citire();
  bktr(0);
  out<<"\nNr de permutari e : "<<nrTot;
  return 0;
}
