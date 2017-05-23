#include <iostream>
#include <fstream>

using namespace std;

ifstream in("quick.in");
ofstream out("quick.out");

int v[101],n;

void citire(){
  in>>n;
  for(int i=1;i<=n;i++)
    in>>v[i];
}

void quick(int inf, int sup){
  int i=inf,j=sup, piv = v[(i+j)/2];

  while(i<=j){
    while(piv>v[i])i++;
    while(piv<v[j])j--;

    if(i<=j){
      int temp = v[i];
      v[i] = v[j];
      v[j] = temp;
      i++;
      j--;
    }
  }
  if(i < sup)
    quick(i,sup);
  if(j > inf)
    quick(inf,j);
}

int main(){
  citire();
  quick(1,n);
  for(int i=1;i<=n;i++)
    out<<v[i]<<' ';
  return 0;
}
