#include <iostream>

using namespace std;

struct nod{
  int info;
  nod * prec , *urm;
};

void adaugareSfarsit(nod * & prim , nod * & ultim , int x){
  nod * deAdaugat = new nod ;
  deAdaugat->info = x;
  deAdaugat->urm = NULL;
  deAdaugat->prec = ultim;

  if(prim == NULL)
    prim = deAdaugat;
  else
    ultim->urm = deAdaugat;

  ultim = deAdaugat;
}

void afisare(nod * ultim){
  nod * i , *j;
  for( i = ultim ; i->prec != NULL ; i = i->prec)
    for(j = i->prec ; j != NULL ; j = j->prec)
      if(i->info % 2 == j->info % 2)
        cout<<" [ "<<i->info<<" ; "<<j->info<<" ]\n";
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

  afisare(ultim);
}

int main(){
  creare();
  return 0;
}
