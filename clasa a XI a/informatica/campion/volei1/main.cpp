#include <iostream>
#include <fstream>

using namespace std;

ifstream in("volei1.in");
ofstream out("volei1.out");

int nrF,nrB , f[2002], b[2002],r[4004];

void citire(){
  in>>nrF;
  for(int i = 1; i <= nrF; ++i)
    in>>f[i];
  f[++nrF] = f[1];
  in>>nrB;
  for(int i = 1; i <= nrB; ++i)
    in>>b[i];
}

void quickSort(int arr[] ,int left ,int right){
  int i = left ,j = right;
  int pivot = arr[(i + j) / 2];
  while(i <= j){
    while(arr[i] < pivot)
      i++;
    while(arr[j] > pivot)
      j--;
    if(i <= j){
      int t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
      i++;
      j--;
    }
  }

  if(i < right)
    quickSort(arr, i, right);
  if(j > left)
    quickSort(arr, left, j);
}

bool ok[2002];

void greedy(){
  int nr = 0 ;
  int ad = 1;
  for(int i = 1; i < nrF; i++){
    r[ad++] = f[i];
    for(int j = 1 ; j <= nrB; j++){
      if(ok[j]==false){
        if(b[j] > f[i] && b[j]>f[i+1]){
          nr++;
          r[ad++] = -b[j];
          ok[j]=true;
          break;
        }
      }
    }
  }
  out<<nr<<'\n';
  for(int i = 1; i < ad; ++i)
    out<<r[i]<<' ';
}

int main(){

  citire();
  quickSort(b,1,nrB);
  greedy();
  return 0;
}
