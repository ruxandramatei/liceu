#include <iostream>
#include <fstream>
#define DIM 100

using namespace std;

ifstream in("pb.in");
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

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(v[i].grad > v[j].grad){
                int aux = v[i].eticheta;
                v[i].eticheta = v[j].eticheta;
                v[j].eticheta = aux;
                aux = v[i].grad;
                v[i].grad = v[j].grad;
                v[j].grad = aux;
            }

}

void rezolvare(){

  for(int i = 0; i < n; ++i){
    v[i].eticheta = i+1;
    v[i].grad = suma(i);
  }

  ordonare();
  out<<"Varfurile de grad par sunt:";
  for(int i = 0; i < n; i++)
    if(v[i].grad%2==0)
        out<<v[i].eticheta<<' ';
    out<<"Iar celelalte:";
    for(int i = n-1; i >= 0; i--)
        if(v[i].grad%2==1)
            out<<v[i].eticheta<<' ';

}

int main(){

  citire();
  rezolvare();
  return 0;

}
