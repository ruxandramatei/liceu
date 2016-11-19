#include <iostream>
#include <fstream>

using namespace std;

ifstream in("Subsiruri.in");
ofstream out("Subsiruri.txt");

struct rez{
  int poz[100],max,nr;
}r[100];

int n, lg;

int cautare(int x){
  for(int i=1; i<=lg;i++){
    if(x>r[i].max)return i;
  }
  return lg+1;
}

void greedy(){
  int x;

  in>>n;
  in>>x;

  r[1].max = x;
  r[1].nr=1;
  r[1].poz[1]=1;
  lg = 1;

  for(int i = 2; i <= n; i++){
    in>>x;
    int poz = cautare(x);
    if(poz > lg){
        lg++;
        r[lg].max = x;
        r[lg].nr++;
        int t = r[lg].nr;
        r[lg].poz[t]=i;
    }
    else{
      r[poz].max = x;
      r[poz].nr++;
      int t = r[poz].nr;
      r[poz].poz[t]=i;
    }
  }

  for(int i=1 ; i <= lg; i++){
    for(int j=1;j<=r[i].nr;j++)
      out<<r[i].poz[j]<<' ';
    out<<'\n';
  }
}

int main(){
  greedy();
  return 0;
}
