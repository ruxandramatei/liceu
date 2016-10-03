//vectori de liste e pb 2
#include <iostream>
#include <string.h>

using namespace std;

struct elementLista{
  char cuv[10];
  elementLista* urm;
};

void afisareInf(elementLista * prim){
  if(prim != 0){
    cout<<prim->cuv<<' ';
    afisareInf(prim->urm);
  }
}

void ordonareInf(elementLista * & prim){
  for(elementLista * i = prim ; i->urm != 0 ; i = i->urm){
    for(elementLista * j = i -> urm ; j != 0 ; j = j->urm){
      if(strlen(i->cuv)>strlen(j->cuv)){
        char aux[10];
        strcpy(aux,i->cuv);
        strcpy(i->cuv,j->cuv);
        strcpy(j->cuv,aux);
      }
    }
  }
}

void adaugareInceputInf(elementLista * & primInf,char cuv1[]){
  elementLista * deAdaugat = new elementLista;
  strcpy(deAdaugat->cuv,cuv1);
  deAdaugat->urm =primInf;
  primInf = deAdaugat;
}

elementLista * prim[30];

void creare(){
  int n;
  cin>>n;
  char cuv[10];
  for(int i = 0 ; i < n ;i++){
    cin>>cuv;
    int x = (int)(cuv[0]-'a');
    adaugareInceputInf(prim[x],cuv);
  }
  for(int i = 0 ; i <= 29 ;i++){
    if(prim[i]!= NULL ){
      ordonareInf(prim[i]);
      afisareInf(prim[i]);
    }
  }
}

int main(){
  creare();
  return 0;
}
