#include <iostream>

using namespace std;

//Stergerea unui numar de ordin dat

struct nod{
  int info;
  nod * prec , * urm;
};

void adaugareSfarsit(nod * & prim , nod * & ultim , int x){
    nod * deAdaugat = new nod ;
    deAdaugat->info = x;
    deAdaugat->urm = NULL;
    deAdaugat->prec = prim;
    if(prim == NULL)prim = deAdaugat;
    else {
      ultim->urm = deAdaugat;
    }
    ultim = deAdaugat;
}

void stergere(nod * & q , nod * & prim , nod * &ultim){

  if(prim ->urm == NULL){
    delete prim;
  }
  else if(prim == q){
    nod * deSters = q;
    prim = prim->urm;
    delete deSters;
  }
  else if(q == ultim){
    nod * deSters = q;
    ultim = ultim->prec;
    delete q;
  }
  else{
    nod * deSters = q;
    q->prec->urm = q->urm;
    q->urm->prec = q->prec;

    delete deSters;
  }
}

void afisare(nod * prim){
   nod * i ;
   for(i = prim ; i!= NULL ; i = i->urm){
     cout<<i->info<<'\n';
   }

}


void creare(){
  int n,x;
  nod * prim , * ultim;
  prim = ultim = NULL;

  cout<<"Cititi numarul de numere , apoi lista :\n";
  cin>>n;

  for(int i = 0 ; i < n ; i++){
    cin>>x;
    adaugareSfarsit(prim , ultim , x);
  }

  cout<<"Cititi numarul de ordine al nodului care va fi sters\n";
  int poz ;
  cin>>poz;
  int k = 1;
  for(nod * i = prim; i != NULL ; i = i->urm ){
    if(k == poz){
      stergere(i,prim,ultim);
      break;
    }
    k++;
  }

  afisare(prim);
}

int main(){
  creare();
  return 0;
}
