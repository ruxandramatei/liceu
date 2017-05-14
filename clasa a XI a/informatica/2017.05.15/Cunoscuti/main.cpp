#include <iostream>
#include <fstream>
//nodul cu gradul maxim interior
using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,m,valMaxima;

void citire(){
  in>>n>>m;
  int x,y;
  for(int i=1;i<=m;i++){
    in>>x>>y;
    a[x][y]=1;
  }
}

void maximAfisare(){
  for(int j=1;j<=n;j++)
    if(valMaxima == a[0][j])
      out<<j<<' ';
}

void calculGradInter(){

  for(int j=1;j<=n;j++){
    for(int i=1;i<=n;i++){
      a[0][j]+=a[i][j];
    }
    if(valMaxima<a[0][j])
      valMaxima=a[0][j];
  }
}

int main(){
  citire();
  calculGradInter();
  maximAfisare();
  return 0;
}
