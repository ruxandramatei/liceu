#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("startrek.in");
ofstream out("startrek.out");

struct nava{
  int dis, vit;
  float timp;
}v[4002];

int n,k;

void citire(){
  in>>n>>k;
  for(int i = 1; i <= n; i++){
    in>>v[i].dis;
  }
  for(int i = 1; i <= n; i++){
    in>>v[i].vit;
    v[i].timp = (float)(v[i].dis/v[i].vit);
  }
}

void sort(){
  for(int i = 1; i < n; i++){
    for(int j = i+1; j <= n; j++){
      if(v[i].timp > v[j].timp){
        nava t = v[i];
        v[i] = v[j];
        v[j] = t;
      }
    }
  }
}

void greedy(){
  int nr = 1, contor = k;
  for(int i = 2; i <= n; i++){
    if(v[i].timp >= contor){
      nr++;
      contor+=k;
    }
  }
  out<<nr;
}

int main(){
  citire();
  sort();
  greedy();
  return 0;
}
