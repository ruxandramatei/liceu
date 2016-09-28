#include <iostream>

using namespace std;

struct nod {
  int info;
  nod * urm , * prec;
};

void adaugareSfarsit(nod * & prim , nod * & ultim , int x){
  nod * deAdaugat = new nod;
  deAdaugat->info = x;
  deAdaugat->urm = NULL;
  deAdaugat->prec = ultim;
  if(prim == NULL)prim = deAdaugat;
  else{
    ultim->urm = deAdaugat;
  }
  ultim = deAdaugat;
}

void afisare(nod * prim){
  for(nod * i = prim ; i ; i = i->urm){
    cout<<i->info<<' ';
  }
}

void inserare(nod * & q){
  nod * deAdaugat = new nod;
  deAdaugat->info = 0;
  deAdaugat->urm = q->urm;
  deAdaugat->prec = q;

  if(q ->urm!= NULL)
    q->urm->prec=deAdaugat;
  if(q != NULL)
    q->urm = deAdaugat;

}

void creare(){
   int n , x;
   nod * prim , * ultim;
   prim = ultim = NULL;
   cout<<"n = \n";
   cin>>n;
   for(int i = 0 ; i < n ; i++){
     cin>>x;
     adaugareSfarsit(prim , ultim ,x);
   }

   for(nod * i = prim ; i ; i = i->urm){
     if(i->info < 0){
       inserare(i);
       i = i->urm;
     }
   }

   afisare(prim);
}

int main(){
  creare();
  return 0;
}
