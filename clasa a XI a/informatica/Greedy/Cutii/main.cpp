#include <iostream>
#include <fstream>

using namespace std;

ifstream in("CUTII.in");
ofstream out("CUTII.txt");

int v1[102],v2[102],n;
int pz;

void citire(){
  in>>n;
  for(int i = 1; i <= n+1; ++i){
    in>>v1[i];
    if(v1[i]==0)pz = i;
  }
  for(int i = 1; i <= n+1; ++i){
    in>>v2[i];
  }
}

int validare(){
  for(int i=1 ; i<=n+1;i++)
    if(v1[i]!=v2[i])
      return i;
  return 0;
}

int cauta(int x){
  for(int i=1; i<=n+1;i++)
    if(v1[i]==x)return i;
}

void greedy(){
  int k=0;
  while(validare()!=0){
    if(v2 [pz] != 0){
      int p = cauta(v2[pz]);
      v1[pz] = v1[p];
      v1[p] = 0;
      pz =p;
      k++;
    }
    else{
      int p =validare();
      int q = cauta(v2[p]);
      v1[pz] = v1[p];
      v1[p]=v1[q];
      v1[q]=0;
      pz = p;
      k+=2;
    }
  }
  out<<k;
}

int main(){
  citire();
  greedy();
  return 0;
}
