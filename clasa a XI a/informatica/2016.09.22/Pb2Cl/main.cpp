//Se citeste un numar de n cuvinte.
//Sa se ordoneze crescator dupa numarul de vocale

#include <iostream>
#include <string.h>

using namespace std;

struct elementListaInferioara{
  char cuvant[20];
  elementListaInferioara * urmatorInferior ;
};

struct elementListaSuperioara{
  int lungimeVocale;
  elementListaInferioara * primInferior ;
  elementListaSuperioara * urmatorSuperior ;
};

 void afisareInferioara(elementListaInferioara * prim){
  if(prim != NULL){
    cout<<prim->cuvant<<'\n';
    afisareInferioara(prim->urmatorInferior);
  }
}

 void afisareSuperioara(elementListaSuperioara * prim){
  if(prim != NULL){
    afisareInferioara(prim->primInferior);
    afisareSuperioara(prim->urmatorSuperior);
  }
}

 void adaugareInceputListaInferioara(elementListaInferioara* & prim, char cuv[]){
  elementListaInferioara * deAdaugat = new elementListaInferioara;
  strcpy(deAdaugat->cuvant,cuv);
  deAdaugat->urmatorInferior = prim ;
  prim = deAdaugat ;
}

 void adaugareInceputListaSuperioara(elementListaSuperioara* & prim , int lung ,
char cuv[]){
  elementListaSuperioara * deAdaugat = new elementListaSuperioara;
  deAdaugat -> lungimeVocale = lung;
  adaugareInceputListaInferioara(deAdaugat->primInferior,cuv);
  deAdaugat->urmatorSuperior = prim;
  prim = deAdaugat ;
}

 void InserareListaSuperioara(elementListaSuperioara* & elementInterior, int lung
, char cuv[]){
  elementListaSuperioara* deAdaugat = new elementListaSuperioara;
  deAdaugat->lungimeVocale = lung;
  adaugareInceputListaInferioara(deAdaugat->primInferior,cuv);
  deAdaugat->urmatorSuperior = elementInterior->urmatorSuperior;
  elementInterior->urmatorSuperior = deAdaugat;
}

int numarVocale(char cuv[]){
  int contor = 0;
  for(int i = 0 ; i < strlen(cuv) ; i++){
    if(strchr("aeiou",cuv[i]))contor++;
  }
  return contor;
}

void rezolvare(elementListaSuperioara* & prim){
  int n , lungim;
  char cuv[20];
  cout<<"Cititi numarul de cuvinte si apoi cuvintele:\n";
  cin>>n;

  for(int i = 0 ; i < n ; i++){
    cin>>cuv;
    lungim = numarVocale(cuv);

    if(prim == NULL || prim->lungimeVocale > lungim){
      adaugareInceputListaSuperioara(prim,lungim,cuv);
    }
    else if(prim->lungimeVocale == lungim){
      adaugareInceputListaInferioara(prim->primInferior,cuv);
    }
    else {
      elementListaSuperioara * parcurgator = prim;

      while(parcurgator->urmatorSuperior != 0){
        if(parcurgator->urmatorSuperior->lungimeVocale >= lungim)break;
        parcurgator = parcurgator->urmatorSuperior;
      }
      if(parcurgator->urmatorSuperior == 0 ){
        if(parcurgator->lungimeVocale == lungim)
          adaugareInceputListaInferioara(parcurgator->primInferior,cuv);
        else InserareListaSuperioara(parcurgator,lungim,cuv);
      }
      else if(parcurgator->urmatorSuperior->lungimeVocale == lungim){
        adaugareInceputListaInferioara(parcurgator->urmatorSuperior->primInferior,
        cuv);
      }
      else if(parcurgator->urmatorSuperior->lungimeVocale > lungim ){
          InserareListaSuperioara(parcurgator,lungim,cuv);
        }
    }
  }
}

int main(){
  elementListaSuperioara* prim = new elementListaSuperioara;
  prim = NULL;
  rezolvare(prim);
  afisareSuperioara(prim);
  return 0;
}
