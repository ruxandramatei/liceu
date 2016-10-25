#include <iostream>
#include <fstream>

using namespace std;

ifstream in("nr.in");
ofstream out("nr.txt");

int n;

int minim(int v[],int lg){//calculam minimul
  int m = v[1];
  for(int i=2;i<=lg;i++)
    if(v[i]<m)m=v[i];
  return m;
}


void init(int v[],int nr[]){//initializare cu 1 la pozitie
  for(int i=1;i<=n;i++){
    v[i]=1;
  }
}

void afis(int v[],int m){//afisare vector
  for(int i=1;i<=m;i++)
    out<<v[i]<<' ';
}

void Greedy(){
  int p[100],nr[100],nrAux[100];
  int vec[100],l=1;
  vec[1]=1;
  int m;
  l=1;
  in>>m;//Nr de nr prime
  in>>n;//Nr de afisat
  for(int i=1;i<=n;i++){
    in>>nr[i];
    nrAux[i]=nr[i];
  }
  init(p,nr);
  while(l!=m){
      int t;
      t = minim(nr,n);
      l++;
      vec[l]=t;//punem minim in vectorul nou

      for(int i=1;i<=n;i++){
        if(nr[i]==t){
          p[i]++;
          nr[i] = nrAux[i] * vec[p[i]];
        }
      }
  }

  afis(vec,m);//afisare

}

int main(){
  Greedy();
  return 0;
}
