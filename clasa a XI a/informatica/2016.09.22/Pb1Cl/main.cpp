//Se citesc de la tastatura n cuvinte de maximum 20 litere. Afisati literele
//in ordine crescatoare a lungimii lor

#include <iostream>
#include <string.h>

using namespace std;

struct elementListaInferioara{
  char cuvant[20];
  elementListaInferioara * urmatorInferior ;
};

struct elementListaSuperioara{
  int lungimeCuvinte;
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
  deAdaugat -> lungimeCuvinte = lung;
  adaugareInceputListaInferioara(deAdaugat->primInferior,cuv);
  deAdaugat->urmatorSuperior = prim;
  prim = deAdaugat ;
}

 void InserareListaSuperioara(elementListaSuperioara* & elementInterior, int lung
, char cuv[]){
  elementListaSuperioara* deAdaugat = new elementListaSuperioara;
  deAdaugat->lungimeCuvinte = lung;
  adaugareInceputListaInferioara(deAdaugat->primInferior,cuv);
  deAdaugat->urmatorSuperior = elementInterior->urmatorSuperior;
  elementInterior->urmatorSuperior = deAdaugat;
}

void rezolvare(elementListaSuperioara* & prim){
  int n , lungim;
  char cuv[20];
  cout<<"Cititi numarul de cuvinte si apoi cuvintele:\n";
  cin>>n;

  for(int i = 0 ; i < n ; i++){
    cin>>cuv;
    lungim = strlen(cuv);

    if(prim == NULL || prim->lungimeCuvinte > lungim){
      adaugareInceputListaSuperioara(prim,lungim,cuv);
    }
    else if(prim->lungimeCuvinte == lungim){
      adaugareInceputListaInferioara(prim->primInferior,cuv);
    }
    else {
      elementListaSuperioara * parcurgator = prim;

      while(parcurgator->urmatorSuperior != 0){
        if(parcurgator->urmatorSuperior->lungimeCuvinte >= lungim)break;
        parcurgator = parcurgator->urmatorSuperior;
      }
      if(parcurgator->urmatorSuperior == 0 ){
        if(parcurgator->lungimeCuvinte == lungim)
          adaugareInceputListaInferioara(parcurgator->primInferior,cuv);
        else InserareListaSuperioara(parcurgator,lungim,cuv);
      }
      else if(parcurgator->urmatorSuperior->lungimeCuvinte == lungim){
        adaugareInceputListaInferioara(parcurgator->urmatorSuperior->primInferior,
        cuv);
      }
      else if(parcurgator->urmatorSuperior->lungimeCuvinte > lungim ){
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
