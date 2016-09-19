//Problema 20 Lsi
//Verificata in terminal
#include <iostream>

using namespace std;

struct Element{
  int info;
  Element* urm;
};

void adaugareSfarsit(Element* &prim,int val){
  Element* deAdaugat = new Element;
  deAdaugat->info=val;
  deAdaugat->urm = NULL;
  if(prim==NULL)prim=deAdaugat;
  else{
    Element * calator = prim;
    while(calator->urm!=NULL){
      calator=calator->urm;
    }
    calator->urm = deAdaugat;
  }
}

int main(){
  int n,a,r;
  Element* prim = new Element;
  prim = NULL;
  cout<<"Cititi n,a,r:";
  cin>>n>>a>>r;
  for(int i = 1 ; i <= n ; i++){
    int val=a+(i-1)*r;
    adaugareSfarsit(prim,val);
  }
  while(prim!=NULL){
    cout<<prim->info<<'\n';
    prim=prim->urm;
  }
  return 0;
}
