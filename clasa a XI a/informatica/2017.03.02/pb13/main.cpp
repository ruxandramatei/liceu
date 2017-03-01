#include <iostream>
#include <fstream>
#define DIM 100

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[DIM][DIM], n ,m,x[10];

struct NOD{
  int eticheta, grad;
}v[10];

void citire(){
    in>>m>>n;
    for(int i=1;i<=2*n; i++){
        in>>x[i];
        if(i>m){
            a[x[n]][x[i]]=a[x[i]][x[n]]=1;
        }
    }

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
            if((v[i].grad > v[j].grad)||(v[i].grad == v[j].grad && v[i].eticheta>v[j].eticheta)){
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

  for(int i = 0; i < 3; i++)
        out<<v[i].eticheta<<' ';

}

int main(){

  citire();
  rezolvare();
  return 0;

}
