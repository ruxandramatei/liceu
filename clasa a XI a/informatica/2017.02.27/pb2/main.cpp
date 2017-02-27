#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define DIM 100;

using namespace std;

ifstream in("neo.in");
ofstream out("neo.out");

int v[20];
int n, m;

void citire(){

  in>>n>>m;
  for(int i = 0; i < m; ++i){
    int x, y;
    in>>x>>y;
    v[x]++;
    v[y]++;
  }

}

void rezolvare(){

  int a = 1;
  char buffer [33];
  char *intStr = itoa(a,buffer,10);
  string s = string(intStr);

  int minim = v[1];

  for(int i = 2; i <= n; i++){
    if(minim > v[i]){
      minim = v[i];
      intStr = itoa(i,buffer,10);
      s = string(intStr);
    }
    else if(minim == v[i]){
      intStr = itoa(i,buffer,10);
      s = s + " " + string(intStr);
    }
  }
  out<<s;

}

int main(){

  citire();
  rezolvare();
  return 0;

}
