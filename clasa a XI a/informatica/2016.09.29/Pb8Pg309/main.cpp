#include <iostream>
#include <fstream>

using namespace std;

ifstream in("LISTE.in");

struct nod {
  int info;
  nod * urm, * prec;
};

void adaugareSfarsit(nod * & prim , nod * & ultim , int x){
  nod * deAdaugat = new nod;
  deAdaugat->info = x;
  deAdaugat->urm = NULL;
  deAdaugat->prec = ultim;
  if(prim == NULL)
    prim = deAdaugat;
  else
    ultim->urm = deAdaugat;
  ultim = deAdaugat;
}

int rasturnat(int nr){
  int ogl = 0;
  while(nr != 0){
    ogl=ogl*10 + nr%10;
    nr/=10;
  }
  return ogl;
}

bool primNr(int x){
  for(int i = 2 ; i < x ; i++){
    if(x%i==0)return false;
  }
  return true;
}

void afisare(nod * prim){
  for(nod * i = prim ; i ; i = i->urm)
    cout<<i->info<<' ';

}

void creare(){
  int n , x;
  cin>>n;

  nod * prim = NULL;
  nod * ultim = NULL;
  nod * prim1 , * ultim1;
  prim1 = ultim1 = NULL;

  for(int i = 0 ; i < n ; i++){
    in>>x;
    adaugareSfarsit(prim , ultim ,x);
  }

  for(nod * i = prim ; i != NULL ; i = i->urm){
    if(primNr(i->info)==true && primNr(rasturnat(i->info))==true)
      adaugareSfarsit(prim1 , ultim1 , rasturnat(i->info));
  }

  afisare(prim1);
}



int main(){

  creare();
  return 0;
}
