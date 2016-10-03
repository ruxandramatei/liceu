#include <iostream>

using namespace std;

struct nod{
  int info;
  nod * urm;
};

void adaugareInceput(nod * & prim , int val){
  nod * deAdaugat = new nod;
  deAdaugat->info = val;
  deAdaugat->urm = prim;
  prim = deAdaugat;
}

nod * primiDeDivizori[100];

void adaugareDivizori(nod * & primDiv , int nr){
  for(int i = 2 ; i < nr ; i++){
    if(nr%i==0)adaugareInceput(primDiv,i);
  }
}

void stergereListaReper(nod * & p){
  nod * deSters = p->urm;
  p->urm = deSters->urm;
  delete deSters;
}

bool cautare(int val,nod * q){
  while(q!=NULL){
    if(q->info==val)return true;
    q=q->urm;
  }
  return false;
}
void afisare(nod * prim){
  if(prim!= 0){
    cout<<prim->info<<' ';
    afisare(prim->urm);
  }
}

void creare(){
  int n;
  cout<<"Cititi numarul de elem. din lista:\n";
  cin>>n;
  cout<<"Cititi lista\n";
  int x;
  nod * prim = new nod;
  prim = NULL;

  for(int i = 1 ; i <= n ; i++){
    cin>>x;
    adaugareInceput(prim,x);
  }
  int contor = 0 ;
  while(prim!=NULL){
    adaugareDivizori(primiDeDivizori[contor],prim->info);
    contor++;
    prim=prim->urm;
  }

  nod * p = primiDeDivizori[0];
  while(p->urm!=NULL){
    bool ok = true;
    for(int i = 1 ; i < n ; i++){
      if(cautare(p->urm->info,primiDeDivizori[i])==false){
        stergereListaReper(p);
        ok = false;
      }
    }
    if(ok==true)p=p->urm;
  }

  for(int i = 1 ; i < n ; i++){
    if(cautare(primiDeDivizori[0]->info,primiDeDivizori[i])==false){
      nod * deSters = primiDeDivizori[0];
      primiDeDivizori[0]= deSters->urm;
      delete deSters;
    }
  }

  afisare(primiDeDivizori[0]);
}

int main(){
  creare();
  return 0;
}
