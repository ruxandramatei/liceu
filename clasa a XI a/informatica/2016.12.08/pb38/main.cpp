#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

struct cub{
  int l,c;
};

int n, r;
cub v[100];
int st[100];

void quick(cub arr[], int left, int right){
  int i=left, j = right;
  int pivot = arr[(i+j)/2].l;
  while(i<=j){
    while(arr[i].l>pivot)
      i++;
    while(arr[j].l<pivot)
      j--;
      if(i<=j){
        arr[0]=arr[i];
        arr[i]=arr[j];
        arr[j]=arr[0];
        i++;
        j--;
  }
}
  if(i<right)
    quick(arr,i,right);
  if(j>left)
    quick(arr,left,j);
}

void citire(){
  in>>n>>r;
  for(int i=1;i<=n;i++)
    in>>v[i].l;
  for(int i=1;i<=n;i++)
    in>>v[i].c;
  quick(v,1,n);
}

void afisare(){
  out<<"(";
  for(int i=1;i<=r;i++)
    out<<v[st[i]].l<<",";
  out<<")\n";
}



bool validare(int k){
  if(v[st[k-1]].c==v[st[k]].c && k>1)
      return false;
  return true;
}

void bkt(int k){
  for(int i=st[k-1]+1;i<=n;i++){
    st[k]=i;
    if(validare(k)){
      if(k==r)
        afisare();
      else
        bkt(k+1);
    }
  }
}

int main(){
  citire();
  st[0]=0;
  bkt(1);
  return 0;
}
