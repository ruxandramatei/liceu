#include <iostream>
#include <fstream>

using namespace std;

ifstream in("maximizare.in");
ofstream out("maximizare.txt");

int a[100], b[100],n,m;

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
  in>>n>>m;
  for(int i=1 ; i<=n ; i++)
    in>>a[i];
  for(int i=1 ; i<=m ; i++)
    in>>b[i];
  quickSort(a,1,n);
  quickSort(b,1,m);
}

void greedy(){
  citire();
  int i,j,s=0;
  for(i=1,j=1;i<=n && a[i]<0 ; i++,j++)s+=a[i]*b[j];
  for(i=n,j=m; i>0 && a[i]>0 ; i--,j--)s+=a[i]*b[j];
  out<<s;
}

int main(){
  greedy();
  return 0;
}
