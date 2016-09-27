#include <iostream>
#include <string.h>

using namespace std;

struct nod {
  char info;
  nod * urm , * ant;
};

void adaugareSfarsit(nod * & prim , nod * & ultim , char val){
  nod * deAdaugat = new nod;
  deAdaugat->info = val;
  deAdaugat->ant = ultim;
  deAdaugat->urm = NULL;

  if(prim == NULL)
    prim = deAdaugat;
  else
    ultim->urm = deAdaugat;

  ultim = deAdaugat;
}

void afisare(nod * prim){
   nod * i = prim ;

   do{
     if(strchr("aeiouAEIOU",i->info)==NULL)
        cout<<i->info<<'\n';

      i = i->urm;
   }while(i!=prim);

}

void creare(){
  int n ;
  char x;
  cout<<"Cititi numarul de caractere ale listei si apoi lista:\n";
  cin>>n;

  nod * prim = new nod;
  nod * ultim = new nod;
  prim = NULL;
  ultim = NULL;

  for(int i = 0 ; i < n ; i++){
    cin>>x;
    adaugareSfarsit(prim,ultim,x);
  }

  afisare(prim);

}

int main(){

  creare();

  return 0;
}
