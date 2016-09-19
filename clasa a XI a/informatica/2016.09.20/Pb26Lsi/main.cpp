#include <iostream>

using namespace std;

struct nod{
  int info;
  nod* urm;
};

void AdaugareSfarsit(nod* &prim, float val){
  nod* deAdaugat = new nod;
  deAdaugat->info = val;
  deAdaugat->urm = NULL;
  if(prim == NULL)prim = deAdaugat;
  else{
    nod* ult = prim;
    while(ult->urm != NULL){
      ult=ult->urm;
    }
    ult->urm=deAdaugat;
  }
}

void afisare(nod * prim){
  while(prim!=NULL){
    cout<<prim->info<<'\n';
    prim = prim->urm;
  }
}

void rezolvare(nod * prim,int n){
    nod * vectorDeListe[100];
    for(int i = 0; i < n; ++i) {
      vectorDeListe[i] = new nod;
      vectorDeListe[i]=NULL;
    }
    int contor = 0;
    for(nod * i = prim ; i != NULL ; i = i->urm){
      for(int divi = 2 ; divi < i->info ; divi++){
        if(i->info % divi == 0 )AdaugareSfarsit(vectorDeListe[contor],divi);
      }
      cout<<"Lista cu divizorii numarului "<<i->info <<" este \n";
      afisare(vectorDeListe[contor]);
      contor++;
    }
}


int main(){
  int numarElLsi;
  nod* prim = new nod;
  prim=NULL;

  cout<<"Cititi nr de el. al listei si apoi lista:\n";
  cin>>numarElLsi;
  float x;
  for(int i = 0; i < numarElLsi; i++){
    cin>>x;
    AdaugareSfarsit(prim,x);
  }
  rezolvare(prim,numarElLsi);
  return 0;
}
