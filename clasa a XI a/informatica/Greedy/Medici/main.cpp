#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("medici.in");
ofstream out("medici.txt");

struct medic{
  int start, finish, time,poz;
}v[101];

int r[101];

int n, m,lg;

void citire(){
  in>>n;
  for(int i = 1; i <= n; i++)
    in>>v[i].start;

  for(int i = 1; i <= n; i++){
    in>>v[i].finish;
    v[i].poz = i;
    v[i].time = abs(v[i].start - v[i].finish);
  }
}

void sort(){
  for(int i = 1; i < n; i++)
    for(int j = i+1; j<= n; j++){
      if(v[i].start > v[j].start){
        v[0] = v[i];
        v[i] = v[j];
        v[j] = v[0];
      }
      if(v[i].start == v[j].start && v[i].time > v[j].time){
        v[0] = v[i];
        v[i] = v[j];
        v[j] = v[0];
      }
    }
}

void greedy(){
    sort();
    int finish = v[1].finish;
    r[1] = v[1].poz;
    lg=1;
    for(int i=2;i<=n;i++){
      if(v[i].start > finish){
        r[++lg]=v[i].poz;
        finish =  v[i].finish;
      }
    }
    out<<lg<<'\n';
    for(int i = 1; i <= lg; ++i)
      out<<r[i]<<' ';
}

int main(){
  citire();
  greedy();
  return 0;
}
