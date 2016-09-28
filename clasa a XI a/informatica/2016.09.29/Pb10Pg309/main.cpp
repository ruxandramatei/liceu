#include <iostream>
#include <fstream>

using namespace std;

struct nod {
  int info;
  nod * urm, * prec;
};

int frecv2 , frecv5;

void adaugareSfarsit(nod * & prim , nod * & ultim , int x){
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



void afisare(nod * prim){
  for(nod * i = prim ; i ; i = i->urm)
    cout<<i->info<<' ';

}

void frecv(int x){
  while(x!=0 && x% 5 == 0){
    frecv5++;
    x/=5;
  }
  while(x!=0 && x% 2 == 0){
    frecv2++;
    x/=2;
  }
}

void rezolvare(nod * prim){
  for(nod * i = prim ; i != NULL ; i = i->urm){
    frecv(i->info);
  }
  cout<<min(frecv2,frecv5);
}

void creare(){
  int n , x;
  cin>>n;

  nod * prim = NULL;
  nod * ultim = NULL;

  for(int i = 0 ; i < n ; i++){
    cin>>x;
    adaugareSfarsit(prim , ultim ,x);
  }

  rezolvare(prim);

}

int main(){

  creare();
  return 0;
}
