#include <iostream>
#include <fstream>

using namespace std;

ifstream in("culmi.in");
ofstream out("culmi.out");

int n , v[10002];

void citire(){
  in>>n;
  for(int i = 1; i<=n; ++i)
    in>>v[i];
}

bool ok[10002];

void greedy(){
  int nr = 0;
  int k = 1;
  while(k<=n){
    if(ok[k]==false){
      int max = v[k];
      for(int i = k+1; i <= n; i++)
        if(v[i]>max && ok[i]==false){
          ok[i]=true;
          max = v[i];
        }
      nr++;
    }
    k++;
  }
  out<<nr;
}

int main(){
  citire();
  greedy();
  return 0;
}
