#include <iostream>

using namespace std;

struct nod{
  int info;
  nod *urm;
};

void inserare(nod * & prim , int nr){
    nod * deAdaugat = new nod;
    deAdaugat->info = nr;
    deAdaugat->urm = prim;
    prim = deAdaugat;
}

int numarare(nod* & prim , int nr){
  int contor = 0;
  for(nod * calator = prim ; calator != NULL ; calator = calator->urm){
    if(calator->info == nr)contor++;
  }
  return contor;
}

void rezolvare(nod * prim ){
  nod * primRez = new nod;
  primRez = NULL;
  for(nod * i = prim ; i != NULL; i = i->urm){
    if(numarare(primRez,i->info) == 0 && numarare(prim,i->info)>=2){
      inserare(primRez,i->info);
    }
  }
  for(nod * i = primRez ; i != NULL; i = i->urm){
    cout<<i->info<<'\n';
  }
}

int main(){
  nod * prim =new nod;
  prim = NULL;
  int n , x;
  cout<<"Cititi numarul de elemente si apoi lista:";
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>x;
    inserare(prim,x);
  }
  rezolvare(prim);

  return 0;
}
