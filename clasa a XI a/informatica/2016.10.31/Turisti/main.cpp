#include <iostream>
#include <fstream>

using namespace std;

ifstream in("turisti.in");
ofstream out("turisti.txt");

int ZileSez , nrGhi , dur , cer;
int v[100];

void quickSort (int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

void citire(){
  in>>ZileSez>>nrGhi>>dur>>cer;
  for(int i=1;i<=cer;i++)
    in>>v[i];
  quickSort(v,1,cer);
}

void greedy(){
    int k=0;
    int s;
    while(nrGhi != 0){
      s=0;
      for(int i=1 ; i<=cer ; i++){
        if(v[i]<ZileSez && v[i]!=0 && v[i]>=s){
          s = v[i] + dur;
          v[i] = 0;
          k++;
        }
      }
      nrGhi--;
    }
    out<<k;
}

int main(){
  citire();
  greedy();
  return 0;
}
