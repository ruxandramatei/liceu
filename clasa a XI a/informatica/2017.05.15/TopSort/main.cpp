#include <iostream>
#include <fstream>

using namespace std;

ifstream in("topsort.in");
ofstream out("topsort.out");

int a[10001][10001],n,m,grNeg[10001],nr;

void citire(){
  in>>n>>m;
  int x,y;
  for(int i=1;i<=m;i++){
    in>>x>>y;
    a[x][y]=1;
    grNeg[y]++;
  }
}

void rez(){
  while(nr!=n){
    for(int i=1;i<=n;i++){
      if(grNeg[i]==0){
        grNeg[i]=2;
        nr++;
        out<<i<<' ';
        for(int j=1;j<=n;j++){
          if(a[i][j]==1){
            a[i][j]=0;
            grNeg[j]--;
          }
        }
      }
    }
  }
}

int main(){
  citire();
  rez();
}
