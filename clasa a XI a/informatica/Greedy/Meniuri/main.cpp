#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream in("MENIU.in");
ofstream out("MENIU.txt");

struct client{
  int timp, poz ;
};

int n ;
client v[1002];

void citire(){
  in>>n;
  for(int i = 1; i <= n; ++i ){
    in>>v[i].timp;
    v[i].poz = i;
  }
}

void quickSort (client arr[], int left, int right) {
      int i = left, j = right;
      client tmp;
      int pivot = arr[(left + right) / 2].timp;

      while (i <= j) {
            while (arr[i].timp < pivot)
                  i++;
            while (arr[j].timp > pivot)
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

void greedy(){
  quickSort(v,1,n);
  long long s = 0;

  for(int i = 1; i <= n; ++i)
    s += (n - i + 1) * v[i].timp;

  out<<fixed<<setprecision(2)<<float(s/n)<<'\n';

  for(int i = 1; i <= n; ++i)
    out<<v[i].poz<<' ';
}

int main(){
  citire();
  greedy();
  return 0;
}
