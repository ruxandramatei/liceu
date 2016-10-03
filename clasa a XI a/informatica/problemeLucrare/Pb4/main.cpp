#include <iostream>

using namespace std;

struct nod{
  int info;
  nod * urm;
};

void afisareInf(nod * prim){
  if(prim != 0){
    cout<<prim->info<<' ';
    afisareInf(prim->urm);
  }
}

void ordonareInf(nod * & prim){
  for(nod * i = prim ; i->urm != NULL ; i = i->urm ){
    for(nod * j = i->urm ; j != NULL ; j = j->urm){
      if(i->info > j->info){
        int aux = i->info ;
        i->info = j->info ;
        j->info = aux ;
      }
    }
  }
}

void adaugInceput(nod * & prim,int val){
  nod * deAdaugat = new nod;
  deAdaugat->info = val;
  deAdaugat->urm = prim;
  prim = deAdaugat;
}

int primaCifra(int x){
  while(x > 9)x/=10;
  return x;
}

nod * elemente[11];

void creare(){
  int n;
  cin>>n;
  int nrCitit;
  for(int i = 0 ; i < n ;i++){
      cin>>nrCitit;
      int cifra = nrCitit%10;
      adaugInceput(elemente[cifra],nrCitit);
  }
  for(int i = 0 ; i <10 ; i++){
    if(elemente[i]!=NULL){
      ordonareInf(elemente[i]);
      afisareInf(elemente[i]);
    }
  }
}
int main(){
  creare();
  return 0;
}
