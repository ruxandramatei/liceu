#include <iostream>

using namespace std;

struct nod{
  int info;
  nod* urm;
};

void adaugare(int n){
  nod * prim =  new nod;
  nod * ultim = new nod;
  prim = ultim = NULL;
  int x ;
  for(int i = 0 ; i < n ; i++){
      cin>>x;
      nod * deAdaugat = new nod;
      deAdaugat->info = x;
      deAdaugat->urm = NULL;
      if(prim == NULL){
        prim = ultim = deAdaugat;
      }
      else{
        nod * i = prim;
        bool ok = false;
        while(i->urm != NULL ){
          if(i->urm->info > x){
            ok = true;
            break;
          }
          i = i->urm;
        }
        if(ok == true || i->urm == NULL){
          deAdaugat->urm = i->urm;
          i->urm = deAdaugat;
        }
        else if(prim->info > x ){
          deAdaugat->urm = prim;
          prim = deAdaugat;
        }
        else if(prim->info < x && prim->urm == NULL ){
          prim->urm = deAdaugat;
        }
      }
  }
  while (prim != NULL) {
    cout<<prim->info<<'\n';
    prim = prim->urm;
  }
}


int main(){
  int numarElLsi;
  nod* prim = new nod;
  prim=NULL;

  cout<<"Cititi nr de el. al listei si apoi lista:\n";
  cin>>numarElLsi;
  adaugare(numarElLsi);
  return 0;
}
