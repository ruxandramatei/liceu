//Problema 17 Lsi
//Verificata in terminal
#include <iostream>

using namespace std;

struct Element{
  float info;
  Element* urm;
};

void AdaugareSfarsit(Element* &prim, float val){
  Element* deAdaugat = new Element;
  deAdaugat->info = val;
  deAdaugat->urm = NULL;
  if(prim == NULL)prim = deAdaugat;
  else{
    Element* ult = prim;
    while(ult->urm != NULL){
      ult=ult->urm;
    }
    ult->urm=deAdaugat;
  }
}

float mediaAritmetica(float val1,float val2){
  return (float)(val1+val2)/2;
}

void inserareDupa(Element* &dupa,Element*inainte){
  Element * deAdaugat = new Element;
  deAdaugat->info = mediaAritmetica(dupa->info,inainte->info);
  deAdaugat->urm = dupa->urm;
  dupa->urm = deAdaugat;
  dupa=deAdaugat;
}

void modif(Element* &prim){
  while(prim->urm!=NULL){
    inserareDupa(prim,prim->urm);
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
  modif(deModificat);
  while(prim!=NULL){
    cout<<prim->info<<'\n';
    prim=prim->urm;
  }
  return 0;
}
