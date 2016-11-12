#include <iostream>
#include <fstream>

using namespace std;

ifstream in("vintage.in");
ofstream out("vintage.out");

struct elem{
  int val, cost, poz;
}v[1002];

int n, k;

void citire(){
  in>>n>>k;
  for(int i = 1; i <= n; i++){
    in>>v[i].val>>v[i].cost;
    v[i].poz = i;
  }
}

void sort(){
  for(int i = 1; i < n; i++){
    for(int j=i+1; j<=n;j++){
      if((v[i].cost >v[j].cost)||(v[i].cost == v[j].cost && v[i].val<v[j].val)){
        elem aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
}


void greedy(){
  int valmax = 0;
  long long costmin = 0;
  int a = n-k+1;
  for(int i = n; i >= a; i--){
    valmax+=v[i].cost;
    costmin+=v[i].val;
  }
  out<<valmax<<' '<<costmin<<'\n';
  for(int i = n; i >= a;i--)
    out<<v[i].poz<<' ';
}

int main(){
  citire();
  sort();
  greedy();
  in.close();
  out.close();
  return 0;
}
