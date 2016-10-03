#include <iostream>
#include <string.h>

using namespace std;

struct elementListaInferioara{
  char cuv[10];
  elementListaInferioara *urm;
};

struct elementListaSuperioara{
  char lit;
  elementListaInferioara * primInf;
  elementListaSuperioara * urm;
};

void afisareInf(elementListaInferioara * prim){
  if(prim != 0){
    cout<<prim->cuv<<' ';
    afisareInf(prim->urm);
  }
}

void OrdoInf(elementListaInferioara * & prim){
  for(elementListaInferioara *i = prim ; i->urm != NULL ; i = i->urm){
    for(elementListaInferioara *j = i->urm;j!= NULL;j = j->urm){
      if(strlen(i->cuv)>strlen(j->cuv)){
        char aux[10];
        strcpy(aux,i->cuv);
        strcpy(i->cuv,j->cuv);
        strcpy(j->cuv,aux);
      }
    }
  }
}

void afisareSupSiOrdo(elementListaSuperioara * prim){
  for(elementListaSuperioara * i = prim ; i!=NULL ;i=i->urm){
    OrdoInf(i->primInf);
    afisareInf(i->primInf);
  }
}

void adaugareInceputInf(elementListaInferioara * & prim, char cuv[]){
  elementListaInferioara * deAdaugat = new elementListaInferioara;
  deAdaugat->urm=prim;
  strcpy(deAdaugat->cuv,cuv);
  prim = deAdaugat;
}

void adaugareInceputListaSuperioara(elementListaSuperioara * & prim,char cuv[]){
    elementListaSuperioara * deAd = new elementListaSuperioara;
    deAd->lit=cuv[0];
    adaugareInceputInf(deAd->primInf,cuv);
    deAd->urm=prim;
    prim=deAd;
}

void InserareListaSuperioara(elementListaSuperioara * & p,char cuv[]){
   elementListaSuperioara * deAd = new elementListaSuperioara;
   deAd->lit=cuv[0];
   adaugareInceputInf(deAd->primInf,cuv);
   deAd->urm=p->urm;
   p->urm = deAd;
}

void creare(elementListaSuperioara *& prim){
  int n;
  char cuvCit[10];
  cin>>n;
  for(int i = 0 ; i < n ; i++){
    cin>>cuvCit;
    char litera = cuvCit[0];
    if(prim==NULL || prim->lit>litera){
        adaugareInceputListaSuperioara(prim,cuvCit);
    }
    else if(prim->lit==litera){
      adaugareInceputInf(prim->primInf,cuvCit);
    }
    else{
      elementListaSuperioara * j = prim;
      while(j->urm != NULL){
        if(j->urm->lit >= litera)break;
        j = j->urm;
      }
      if(j->urm == 0){
        if(j->lit==litera ){
          adaugareInceputInf(j->primInf,cuvCit);
        }
        else InserareListaSuperioara(j,cuvCit);
      }
      else if(j->urm->lit > litera){
        InserareListaSuperioara(j,cuvCit);
      }
      else if(j->urm->lit == litera){
        adaugareInceputInf(j->primInf,cuvCit);
      }
    }
  }
}

int main(){
  elementListaSuperioara * prim = new elementListaSuperioara;
  prim = NULL;
  creare(prim);
  afisareSupSiOrdo(prim);
  return 0;
}
