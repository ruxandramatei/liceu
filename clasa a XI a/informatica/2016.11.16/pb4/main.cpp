#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb4.in");
ofstream out("pb4.txt");

int st[9], n, v[9];
int nrTot;

void citire(){
  in>>n;
  int k = 0;
  while(n!=0){
    k++;
    v[k]=n%10;
    n/=10;
  }
  n=k;
}

void afisare(){
  for(int i = 1; i <= n; i++)
    out<<v[st[i]];
  out<<"\n";
}

int creare(){
  int rez = 0;
  for(int i=1;i<=n;i++){
    rez=rez*10 +v[i];
  }
  return rez;
}

bool prim(int x){
  if(x!=2 && x%2 == 0)return true;
  for(int i = 3; i*i <= x; i+=2)
    if(x%i==0)return false;
  return true;
}

bool validare(int k){
  for(int i = 1; i < k; i++)
    if(st[i] == st[k])return false;
  return true;
}

bool solutie(int k){
  if(k == n)return true;
  return false;
}

void bktr(int k){
  for(int i = 1; i <= n; i++){
    st[k] = i;
    if(validare(k)){
      if(solutie(k)){
        int nr = creare();
        if(prim(nr)){
          afisare();
          nrTot++;
        }
      }
      else
        bktr(k+1);
    }
  }
}

int main(){
  citire();
  bktr(1);
  out<<"\nNr de permutari e : "<<nrTot;
  return 0;
}
