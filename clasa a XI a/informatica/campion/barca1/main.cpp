#include <iostream>
#include <fstream>

using namespace std;

ifstream in("barca1.in");
ofstream out("barca1.out");

struct nod{
  int info,poz;
  nod *st,*dr;
};

int n, m;
long long g,s;
int indici[11];

void creare(nod *& rad,int x, int p){
  if(rad==NULL){
    rad = new nod;
    rad->info = x;
    rad->poz = p;
    rad->st = NULL;
    rad->dr = NULL;
  }
  else{
    if(rad->info>x)
      creare(rad->st,x,p);
    else
      creare(rad->dr,x,p);
  }
}

nod * caut(nod *rad){
  if(rad->dr == NULL)
    return rad;
  else {
    caut(rad->dr);
  }
}

void stergere(nod *rad,nod * deSters){
  if(rad == deSters){
    rad = rad->st;
    delete deSters;
  }
  else if(rad->dr == deSters){
    rad->dr = NULL;
    delete deSters;
  }
  else{
    stergere(rad->dr,deSters);
  }
}

nod * rad;

void citire(){
  in>>n>>g>>m;
  int x;
  for(int i = 1; i <= 10; ++i){
    in>>indici[i];
  }
  for(int i = 1; i<=n+m;i++){
    in>>x;
    bool ok = false;
    s+=x;

    for(int j = 1; j <= 10; j++)
      if(i == indici[j]){
        ok = true;
      }

    if(ok == true)
      out<<"\n0\n";

    if(s<=g)
      creare(rad,x,i);
    else{
      nod * maxim = caut(rad);
      if(ok == false)out<<i<<'\n';
      s-=maxim->info;
      stergere(rad,maxim);
      creare(rad,x,i);
    }
  }
}

int main(){
  citire();
  return 0;
}
