#include <iostream>
#include <string.h>

using namespace std;

struct nod{
  char info;
  nod * prec , * urm;
};

void adaugareSfarsit(nod * & prim , nod * & ultim, char x){
    nod * deAdaugat = new nod ;
    deAdaugat->info = x ;
    deAdaugat->urm = NULL;
    deAdaugat->prec = ultim;

    if(prim == NULL)
      prim = deAdaugat;
    else
      ultim->urm = deAdaugat;

    ultim = deAdaugat;

}

void afisare(nod * prim , nod * ultim){
    nod * i = ultim ;
    
    while(i != NULL){
      cout<<i->info<<'\n' ;
      i = i->prec ;
    }
}

void creare(){
    char cuv[26];
    nod * prim , * ultim;
    prim = ultim = NULL;

    cout<<"Cititi cuvantul :\n";

    cin>>cuv;

    for(int i = 0 ; i < strlen(cuv) ; i++){
      adaugareSfarsit(prim , ultim , cuv[i]);
    }

    afisare(prim ,ultim);
}

int main(){
  creare();
  return 0;
}
