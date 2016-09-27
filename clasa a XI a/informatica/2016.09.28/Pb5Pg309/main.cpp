#include <iostream>

using namespace std;

struct nod{
  int info;
  int frecv;
  nod * prec , *urm;
};

void adaugareSfarsit(nod * & prim , nod * & ultim , int x){
  nod * deAdaugat = new nod ;
  deAdaugat->info = x;
  deAdaugat->frecv= 1;
  deAdaugat->urm = NULL;
  deAdaugat->prec = ultim;

  if(prim == NULL)
    prim = deAdaugat;
  else
    ultim->urm = deAdaugat;

  ultim = deAdaugat;
}

void afisare(nod * prim){
  nod * i ;
  for(i = prim ; i!= NULL ; i = i->urm){
    cout<<i->info<<' '<<i->frecv<<'\n';
  }
}

void validare(nod * prim , int val , nod * &poz){
  int k = 0;
  for(nod * i = prim ; i!= NULL ; i = i->urm){
    if(i->info == val){
      poz = i;
      return;
    }
  }
  poz=NULL;
}

void creare(){
  int n,x;
  nod * prim , * ultim;
  prim = ultim = NULL;

  cout<<"Cititi numarul de numere , apoi lista :\n";
  cin>>n;

  for(int i = 0 ; i < n ; i++){
    cin>>x;
    nod * p ;
    validare(prim,x,p);
    if(p==NULL)adaugareSfarsit(prim , ultim , x );
    else{
      p->frecv++;
    }
  }
  afisare(prim);
}

int main(){
  creare();
  return 0;
}
