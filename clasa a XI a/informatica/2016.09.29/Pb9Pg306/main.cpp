#include <iostream>
#include <fstream>

using namespace std;

struct nod{
  int info;
  nod * urm , * prec;
};

void adaugareSfarsit(nod * & prim , nod * & ultim ,int x){
  nod * deAdaugat = new nod;
  deAdaugat->info = x;
  deAdaugat->urm = NULL;
  deAdaugat->prec = ultim;
  if(prim == NULL)
    prim = deAdaugat;
  else
    ultim->urm = deAdaugat;
  ultim = deAdaugat;
}

ifstream in("NR.TXT");


void afisare(nod * prim){
  for(nod * i = prim ; i ; i = i->urm)
    cout<<i->info<<' ';

}

void creare(){
  int n , x;
  in>>n;
  nod * prim , * ultim;
  prim = ultim = NULL;
  for(int i = 0 ; i < n ; i++){
    in>>x;
    adaugareSfarsit(prim,ultim,x%10);
  }
  afisare(prim);
}

int main(){
  creare();
  return 0;
}
