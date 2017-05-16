#include <iostream>
#include <fstream>

using namespace std;

ifstream in("drum_hamiltonian.in");
ofstream out("drum_hamiltonian.out");

int a[101][101],n;
bool ok;
int st[101],viz[101];

void citire(){
  in>>n;
  int x,y;
  while(in>>x>>y){
    a[x][y]=1;
  }
}

void bkt(int k){
  if(ok==false){
    for(int i=1;i<=n;i++){
      if(viz[i]==0 && (k==1 ||a[st[k-1]][i]==1)){
        st[k]=i;
        viz[i]=1;
        if(k==n){
          out<<"1\n";
          for(int j=1;j<=n;j++)
            out<<st[j]<<' ';
          ok=true;
        }
        else if(k<n)
          bkt(k+1);
        viz[i]=0;
      }
    }
  }
}

int main(){
  citire();
  for(int i=1;i<=n;i++){
    if(viz[i]==0 && ok==false){
      st[1]=i;
      viz[i]=1;
      bkt(2);
      viz[i]=0;
    }
  }
  return 0;
}
