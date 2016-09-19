//Problema 18 Lsi
//verificata in terminal
#include <iostream>
#include <math.h>

using namespace std;

struct Element{
  int info;
  Element* urm;
};

void AdaugareSfarsit(Element* &prim,int val){
  Element * deAdaugat = new Element;
  deAdaugat->info = val;
  deAdaugat->urm = NULL;

  if(prim==NULL)prim= deAdaugat;
  else{
    Element*parcurg = prim;
    while(parcurg->urm!=NULL){
      parcurg=parcurg->urm;
    }
    parcurg->urm=deAdaugat;
  }
}

void inserareDupa(Element* dupa,int val){
  Element * deAdaugat = new Element;
  deAdaugat->info = val;
  deAdaugat->urm= dupa->urm;
  dupa->urm = deAdaugat;
  dupa=deAdaugat;
}

void ins(Element* q){
  int val = (int)sqrt(q->info);
  inserareDupa(q,val);
}

void rezolvare(Element * &prim){
  while (prim!=NULL) {
    if(pow((int)sqrt(prim->info),2)==prim->info){
      inserareDupa(prim,(int)sqrt(prim->info));
    }
    prim=prim->urm;
  }
}

int main(){
  int numarElLsi;
  Element* prim = new Element;
  prim=NULL;

  cout<<"Cititi nr de el. al listei si apoi lista:\n";
  cin>>numarElLsi;
  float x;
  for(int i = 0; i < numarElLsi; i++){
    cin>>x;
    AdaugareSfarsit(prim,x);
  }
  Element* deModificat = prim;
  rezolvare(deModificat);
  while(prim!=NULL){
    cout<<prim->info<<'\n';
    prim=prim->urm;
  }
  return 0;
}
