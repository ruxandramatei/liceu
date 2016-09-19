//Problema 21
//Verificata in terminal
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream in("citire.in");

struct Element{
  char cuvant[31];
  Element * urm;
};

void AdaugareSfarsit(Element*& prim,char val[30]){
  Element * deAdaugat = new Element;
  strcpy(deAdaugat->cuvant,val);
  deAdaugat->urm = NULL;
  if(prim==NULL)prim=deAdaugat;
  else{
    Element* i= prim;
    while (i->urm != NULL) {
      i=i->urm;
    }
    i->urm=deAdaugat;
  }
}

void creeare(Element* &prim){
  char x[31];
  while(in>>x){
    AdaugareSfarsit(prim,x);
  }
}

bool cautare(Element* prim ,char val[30]){
  for(Element* i = prim ; i!=NULL ;i=i->urm)
    if(strcmp(prim->cuvant,val)){
      return true;
    }
  return false;

}

int main(){
  Element* prim = new Element;
  prim = NULL;
  creeare(prim);
  char cuv[31];
  strcpy(cuv,"bacalaureat");
  bool ok = cautare(prim,cuv);
  if(ok == true)cout<<"NU\n";
  else cout<<"DA\n";
  return 0;
}
