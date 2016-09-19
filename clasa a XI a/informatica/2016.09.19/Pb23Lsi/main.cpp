//Problema 23
//Varificata in terminal

#include <iostream>

using namespace std;

struct Element{
  float inaltime;
  char gen;
  Element * urm;
};

void AdaugareSfarsit(Element* &prim,float val,char G){
  Element * deAdaugat = new Element;
  deAdaugat->inaltime = val;
  deAdaugat->gen = G;
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

void Sortare(Element* prim){
  for(Element * i = prim ; i->urm != NULL ; i=i->urm){
    for(Element *j = i->urm ; j!=NULL ; j=j->urm){
      if(i->inaltime > j->inaltime && i->gen=='M' && j->gen=='M'){
        float aux = i->inaltime;
        i->inaltime = j->inaltime;
        j->inaltime = aux;

      }
    }
  }
}

int main(){
  int numarElLsi;
  Element* prim = new Element;
  prim=NULL;

  cout<<"Cititi nr de el. al listei si apoi lista:\n";
  cin>>numarElLsi;
  float x;
  char g;
  for(int i = 0; i < numarElLsi; i++){
    cin>>g>>x;
    AdaugareSfarsit(prim,x,g);
    cin>>g;
  }
  Sortare(prim);
  while(prim!=NULL){
    cout<<prim->gen<<' '<<prim->inaltime<<'\n';
    prim=prim->urm;
  }
  return 0;
}
