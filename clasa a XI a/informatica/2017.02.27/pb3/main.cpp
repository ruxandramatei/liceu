#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("graf.in");
ofstream out("graf.out");

int n, k1, k2;
string s[20];

struct NOD{
  int eticheta, grad;
}v1[10], v2[10];

void citire(){

  in>>n;
  for(int i = 0; i < n; i++)
    in>>s[i];

}

int suma(int L){

  int sum = 0;
  for(int i = 0; i<s[L].length(); ++i)
    if(s[L][i]=='x')
      sum++;
  return sum;

}

void ordonare(NOD v[], int k){

    for(int i = 0; i < k-1 ;i++)
        for(int j = i+1; j < k; j++)
            if (v[i].grad > v[j].grad){
                int aux = v[i].grad;
                v[i].grad = v[j].grad;
                v[j].grad = aux;
                aux = v[i].eticheta;
                v[i].eticheta = v[j].eticheta;
                v[j].eticheta = aux;
            }

}

void rezolvare(){
  for(int i = 0; i < n; ++i){
      int a = suma(i);
      if(a % 2 == 0){
        v2[k2++].grad = a;
        v2[k2-1].eticheta = i+1;
      }
      else{
        v1[k1++].grad = a;
        v1[k1-1].eticheta = i+1;
      }
  }

  ordonare(v2, k2);
  ordonare(v1, k1);

  for(int i = 0; i < k2; i++)
    out<<v2[i].eticheta<<' ';
  out<<'\n';
  for(int i = 0; i < k1; i++)
    out<<v1[i].eticheta<<' ';

}

int main(){

  citire();
  rezolvare();
  return 0;
}
