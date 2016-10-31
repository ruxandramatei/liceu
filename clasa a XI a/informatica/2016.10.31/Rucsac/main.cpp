#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream in("rucsac.in");
ofstream out("rucsac.txt");

struct ob{
  int poz;
  float g,val;
  float pUnitar;
};

ob v[100];
float G;
int n;
void quickSort (ob arr[], int left, int right) {
      int i = left, j = right;
      ob tmp;
      float pivot = arr[(left + right) / 2].pUnitar;

      while (i <= j) {
            while (arr[i].pUnitar > pivot)
                  i++;
            while (arr[j].pUnitar < pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

void citire(){
  in>>n;
  in>>G;
  for(int i=1;i<=n;i++){
    in>>v[i].g;
    v[i].poz=i;
  }
  for(int i=1;i<=n;i++){
    in>>v[i].val;
    v[i].pUnitar =(float)(v[i].val / v[i].g);
  }
  quickSort(v,1,n);
}

void greedy(){
  int rez[100],k=0;
  float castig = 0;
  int contor = 1;
  while(G>0){
    if(v[contor].g<=G){
      rez[++k]=v[contor].poz;
      castig+=v[contor].val;
      G-=v[contor].g;
    }
    else {
      rez[++k]=v[contor].poz;
      castig+=G*v[contor].pUnitar;
      G = 0;
    }
    contor++;
  }
  out<<fixed<<setprecision(2)<<castig<<'\n';
  for(int i=1;i<=k;i++)
    out<<rez[i]<<' ';
}

int main(){
  citire();
  greedy();
  return 0;
}
