#include <iostream>
#include <fstream>
#define inf 1001

using namespace std;

ifstream in("royfloyd.in");
ofstream out("royfloyd.out");

int a[101][101],n;

void citire(){
  in>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      in>>a[i][j];
      if(a[i][j]==0 && i!=j)
        a[i][j]=inf;
    }
}

int minim(int a, int b){
  if(a<b)
    return a;
  return b;
}

void royfloyd(){
  for(int through=1;through<=n;through++)
    for(int from=1;from<=n;from++)
      if(a[from][through]!=inf && through != from){
        for(int to=1;to<=n;to++)
          if(a[through][to]!=inf && through != to){
            int temp = a[from][through] + a[through][to];
            a[from][to]= minim(temp, a[from][to]);
          }
      }
}

void afisare(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      out<<a[i][j]<<' ';
    out<<'\n';
  }
}

int main(){
  citire();
  royfloyd();
  afisare();
  return 0;
}
