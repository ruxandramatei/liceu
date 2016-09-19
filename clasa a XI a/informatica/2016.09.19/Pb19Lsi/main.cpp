//Problema 19 Lsi
//Verificata in terminal

#include <iostream>

using namespace std;

struct Element{
  int info;
  Element* urm;
};

void AdaugareSfarsit(Element* &prim,int val){
  Element* deAdaugat= new Element;
  deAdaugat->info = val;
  deAdaugat->urm = NULL;

  if(prim==NULL)prim = deAdaugat;
  else{
    Element* deModificat = prim;
    while (deModificat->urm!=NULL) {
      deModificat=deModificat->urm;
    }
    deModificat->urm=deAdaugat;
  }
}

void StergereVal(Element* &prim,int val){
  for(Element *i = prim ; i->urm != NULL;){
    if(i->urm->info==val){
      Element* deSters = i->urm;
      i->urm=i->urm->urm;
      delete deSters;
    }
    else i=i->urm;
  }
  if(prim->info == val){
    Element * deSters = prim;
    prim = prim->urm;
    delete deSters;
  }
}

int minim(Element* prim){
  int mini=prim->info;
  prim=prim->urm;
  while(prim!=NULL){
    if(prim->info < mini)mini = prim->info;
    prim=prim->urm;
  }
  return mini;
}

void rezolvare(Element * &prim){
  int m1 = minim(prim);
  StergereVal(prim,m1);
  int m2 = minim(prim);
  StergereVal(prim,m2);
  int m3 = minim(prim);
  StergereVal(prim,m3);

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
  rezolvare(prim);
  Element* deParcurs = prim;
  while(deParcurs!=NULL){
    cout<<deParcurs->info<<'\n';
    deParcurs=deParcurs->urm;
  }
  return 0;
}
