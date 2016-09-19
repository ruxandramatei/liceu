//problema numarul 16 Lsi
//Vetificata in terminal

#include <iostream>

using namespace std;

struct Element{
  int info;
  Element* urmator;
};

int nrElemLsi1,nrElemLsi2;

void AdaugareInceput(Element* & prim ,int val){
  Element * deAdaugat = new Element;
  deAdaugat->info = val;
  deAdaugat->urmator = prim;
  prim = deAdaugat;
}

bool validare(int val1 , int val2){
  if(val1 == val2)return true;
  return false;
}

bool esteDejaInLsi(int val,Element* prim){
  while(prim!=NULL){
    if(prim->info == val)return true;
    prim=prim->urmator;
  }
  return false;
}

int lungime(Element* prim){
  int contor = 0;
  while(prim!=NULL){
    contor++;
    prim=prim->urmator;
  }
  return contor;
}

bool rezolvare(Element *primLsi1,Element*primLsi2){
  int contor = 0;
  int lungimeLsi2 = lungime(primLsi2);
  for(Element* calator = primLsi2 ; calator !=NULL; calator=calator->urmator){
    if(esteDejaInLsi(calator->info ,primLsi1))contor++;
  }
  if(contor==lungimeLsi2)return true;
  return false;
}

int main(){
  Element* primLsi1 = new Element;
  Element* primLsi2 = new Element;
  primLsi1 = primLsi2 = NULL;
  int citit;

  cout<<"Cititi numarul de el. al listelor si apoi listele:\n";
  cin>>nrElemLsi1>>nrElemLsi2;

  for(int i = 0; i < nrElemLsi1; i++){
    cin>>citit;
    if(!esteDejaInLsi(citit,primLsi1))AdaugareInceput(primLsi1,citit);
  }

  for(int i = 0; i < nrElemLsi2; i++){
    cin>>citit;
    if(!esteDejaInLsi(citit,primLsi2))AdaugareInceput(primLsi2,citit);
  }

  bool test = rezolvare(primLsi1,primLsi2);
  if(test)cout<<"Toate elementele listei 2 se gasesc in lista 1\n";
  else cout<<"Elementele listei 2 nu se gasesc in totalitate in lista 1\n";
  return 0;
}
