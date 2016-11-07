#include <iostream>
#include <fstream>

using namespace std;

ifstream in("Minimizare.in");
ofstream out("Minimizare.txt");

int a[102], b[102], n, m;

void citire(){
  in>>n>>m;
  for(int i = 1; i <= n; ++i){
    in>>a[i];
  }
  for(int i = 1; i <= m; ++i){
    in>>b[i];
  }
}

void sort(int arr[], int lg){
  int p;
  for(int i = 1; i < lg; i++){
    p = i;
    for(int j = i + 1; j <= lg; ++j){
      if(arr[p] > arr[j])
        p=j;
    }
    arr[0] = arr[i];
    arr[i] = arr[p];
    arr[p] = arr[0];
  }
}

void greedy(){
  sort(a,n);
  sort(b,m);
  int E = 0;

  for(int i = 1, j = m ; a[i] < 0 && i<=n ; ++i, --j)
    E+= a[i]*b[j];
  for(int i = n, j = 1 ; a[i] > 0 && i > 0 ; --i, ++j)
    E+= a[i]*b[j];
  out<<E;
}

int main(){

  citire();
  greedy();

  return 0;
}
