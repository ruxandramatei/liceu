#include <iostream>
#include <fstream>

using namespace std;

ifstream in("bubble.in");
ofstream out("bubble.out");

void citire(int &dim,int v[101]){
  in>>dim;
  for(int i=1;i<=dim;i++)
    in>>v[i];
}

void bubble(int v[101], int dim){
  bool ok ;
  do{
    ok = true;
    for(int i=1;i<dim;i++)
      if(v[i]>v[i+1]){
        int temp = v[i];
        v[i] = v[i+1];
        v[i+1] = temp;
        ok = false;
      }
  }while(ok==false);
}

int main(){
  int v[101],n;
  citire(n,v);
  bubble(v,n);
  for(int i=1;i<=n;i++)
    out<<v[i]<<' ';
  return 0;
}
