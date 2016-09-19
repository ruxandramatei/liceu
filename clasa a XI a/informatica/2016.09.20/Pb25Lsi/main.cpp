#include <iostream>

using namespace std;

struct nod{
  int info;
  nod * urm;
};

nod * creare(){
  cout<<"Cititi numarul de elemente al listei apoi lista :";
  int n;
  cin>>n;
  nod * prim = new nod;
  nod * ultim = new nod;
  prim = ultim = NULL;
  for(int i = 0 ; i < n ; i++){
    nod * p = new nod;
    int x;
    cin>>x;
    p->info = x;
    p->urm = NULL;
    if(prim == NULL)prim = p;
    else ultim->urm = p;
    ultim = p;
  }
  return prim;
}

void adaugareSfarsit(nod * & prim , int val){
  nod * deAdaugat = new nod;
  deAdaugat->info = val;
  deAdaugat->urm = NULL;
  if(prim == NULL)prim = deAdaugat;
  else{
    nod * i = prim;
    while(i->urm != NULL){
      i = i->urm;
    }
    i->urm=deAdaugat;
  }
}

void afisare(nod * prim){
  while(prim!=NULL){
    cout<<prim->info<<'\n';
    prim = prim->urm;
  }
}

void rezolvare(nod * prim , nod * & prim1 , nod * & prim2){
  while(prim != NULL){
    if(prim->info < 0)adaugareSfarsit(prim1,prim->info);
    else if(prim->info > 0)adaugareSfarsit(prim2,prim->info);
    prim = prim->urm;
  }
}

int main(){
  nod* prim = new nod;
  prim = creare();
  nod * prim1 = new nod;
  prim1 = NULL;
  nod * prim2 = new nod;
  prim2 = NULL;
  rezolvare(prim,prim1,prim2);
  cout<<"LISTA 1 : -cuprinde numerele negative -\n";
  afisare(prim1);
  cout<<"LISTA 2 : -cuprinde numerele pozitive -\n";
  afisare(prim2);
  return 0;
}
