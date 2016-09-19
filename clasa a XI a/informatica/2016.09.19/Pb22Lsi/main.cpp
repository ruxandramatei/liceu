//Problema 22 Lsi
//Verificata in terminal

#include <iostream>

using namespace std;

struct Element{
  int info;
  Element * urm;
};

void AdaugareInceput(Element * & prim, int val){
  Element* deAdaugat = new Element;
  deAdaugat->info = val;
  deAdaugat->urm=prim;
  prim = deAdaugat;

}

void Sortare(Element* prim){
  for(Element * i = prim ; i->urm != NULL ; i=i->urm){
    for(Element *j = i->urm ; j!=NULL ; j=j->urm){
      if(i->info > j->info){
        int aux = i->info;
        i->info = j->info;
        j->info = aux;
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
  for(int i = 0; i < numarElLsi; i++){
    cin>>x;
    AdaugareInceput(prim,x);
  }
  Sortare(prim);
  while(prim!=NULL){
    cout<<prim->info<<'\n';
    prim=prim->urm;
  }
  return 0;
}
