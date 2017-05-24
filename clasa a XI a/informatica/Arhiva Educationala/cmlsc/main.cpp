#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1025],b[1025],n,m;
int rez[1025][1025],nr,afis[1025];

void citire(){
  in>>n>>m;
  for(int i=1;i<=n;i++){
    in>>a[i];
  }
  for(int i=1;i<=m;i++){
    in>>b[i];
  }
}

int maxim(int a, int b){
  if(a>b)
    return a;
  else
    return b;
}

void afisareDrum(){
  int i=m, j=n, val = rez[i][j];
  do{
    while(rez[i][j]==val){
      j--;
    }
    j++;
    while(rez[i][j]==val){
      i--;
    }
    i++;
    if(b[i]==a[j]){
      afis[++afis[0]]=a[j];
      val--;
    }
    i--;
  }while(val!=0);

  for(int i=afis[0];i>=1;i--)
    out<<afis[i]<<' ';
}

void cmlsc(){
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(b[i] != a[j]){
        rez[i][j]=maxim(rez[i][j-1],rez[i-1][j]);
      }
      else{
        rez[i][j]=rez[i-1][j-1]+1;
        nr++;
      }
    }
  }
  out<<rez[m][n]<<'\n';
  if(rez[m][n]!=0)afisareDrum();
}

int main(){
  citire();
  cmlsc();
  return 0;
}
