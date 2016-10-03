#include <iostream>
#include <string.h>

using namespace std;

struct nod{
  char litera;
  nod * urm;
};

bool validare(nod * prim, char val){
  for(nod * i = prim ; i != NULL ; i = i->urm){
    if(i->litera == val)return true;
  }
  return false;
}

void adaugareSfarsit(nod *& prim,nod * & ultim,char val){
  nod * deAdaugat = new nod;
  deAdaugat ->litera = val;
  deAdaugat ->urm = NULL;
  if(prim == NULL)prim=deAdaugat;
  else{
    ultim->urm=deAdaugat;
  }
  ultim = deAdaugat;
}

void creare(char s[200],nod * & prim){
  nod * ultim = new nod;
  ultim = NULL;
  for(int i = 0 ; i < strlen(s) ; i++){
    if(validare(prim , s[i])==false){
      adaugareSfarsit(prim,ultim,s[i]);
    }
  }
}

void afisare(nod * prim){
  if(prim != 0){
    cout<<prim->litera;
    afisare(prim->urm);
  }
}

void intersectie(nod * prim1 , nod * prim2 , nod * & prim3){
  nod * ultim = new nod;
  ultim = NULL;
  for(nod * i = prim1 ; i != NULL ; i = i->urm){
    if(validare(prim2,i->litera)== true){
      adaugareSfarsit(prim3,ultim,i->litera);
    }
  }
}

nod * v[4];

int main(){
  char sir1[100], sir2[100];
  cin.getline(sir1,100);
  cin.getline(sir2,100);
  creare(sir1,v[0]);
  creare(sir2,v[1]);
  intersectie(v[0],v[1],v[2]);
  afisare(v[2]);
  return 0;
}
