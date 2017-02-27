#include <iostream>
#include <fstream>
#define DIM 100

using namespace std;

ifstream in("neo.in");
ofstream out("neo.out");

int a[DIM][DIM], n ;

struct NOD{
  int eticheta, grad;
}v[10];

void citire(){

  in>>n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; j++)
      in>>a[i][j];

}

int suma(int Linie){

  int s = 0;
  for(int i = 0; i < n; ++i)
    s+=a[Linie][i];
  return s;

}

void ordonare(){

    bool ok ;
    do{
      ok = false;
      for(int i = 0 ; i < n - 1; ++i)
        for(int j = i+1; j < n; j++)
          if(v[i].grad > v[j].grad){
            ok = true;
            v[0] = v[i];
            v[i] = v[j];
            v[j] = v[0];
          }
    }while(ok==true);

}

void rezolvare(){

  for(int i = 0; i < n; ++i){
    v[i].eticheta = i+1;
    v[i].grad = suma(i);
  }

  ordonare();
  for(int i = 0; i < n; i++)
        out<<v[i].eticheta<<' '<<v[i].grad<<'\n';

}

int main(){

  citire();
  rezolvare();
  return 0;

}
