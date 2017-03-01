#include <iostream>
#include <fstream>
#define DIM 100

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[DIM][DIM], n ,m;

struct NOD{
  int eticheta, grad;
}v[10];

void citire(){
    in>>m>>n;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0){
            a[x][y]=a[y][x]=1;

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

  for(int i = 0; i < n; i++)
        out<<v[i].eticheta<<' ';

}

int main(){

  citire();
  rezolvare();
  return 0;

}
