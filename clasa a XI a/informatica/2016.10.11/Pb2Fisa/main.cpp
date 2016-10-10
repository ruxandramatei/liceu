#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream in("citire.in");

//Nodul care va face parte din arbore
struct nod{
  char info;
  nod * st, *dr;
};

//Citirea si construirea arborelui
void citire(nod * & rad){
  char caracter;
  in>>caracter;
  if(caracter == '.')
    rad = NULL;
  else {
    //Cream radacina noua
    rad = new nod;
    rad->info = caracter;
    //Mergem pe stanga si apoi pe dreapta
    citire(rad->st);
    citire(rad->dr);
  }
}

//Afisarea vocalelor RSD
void afisVocRSD(nod* rad){
  if(rad != NULL){
    if(strchr("EAIOUaeiou",rad->info)!=0)
      cout<<rad->info<<' ';
    afisVocRSD(rad->st);
    afisVocRSD(rad->dr);
  }
}

//Afisarea vocalelor SDR
void afisVocSDR(nod* rad){
  if(rad != NULL){
    afisVocSDR(rad->st);
    afisVocSDR(rad->dr);
    if(strchr("EAIOUaeiou",rad->info)!=0)
      cout<<rad->info<<' ';
  }
}

int numarCons(nod * rad){
  if(!rad)
    return 0;
  else{
    if(strchr("EAIOUaeiou",rad->info)==0)
      return 1 + numarCons(rad->st) + numarCons(rad->dr);
    return numarCons(rad->st) + numarCons(rad->dr);
  }
}

int sumaAscii(nod * rad){
  if(!rad)
    return 0;
  else{
    return (int)rad->info + sumaAscii(rad->st) + sumaAscii(rad->dr);
  }
}

int numarFrunze(nod * rad){
  if(rad == NULL)return 0;
  if((rad ->st == NULL) && (rad->dr == NULL)) return 1;
  return numarFrunze(rad->st) + numarFrunze(rad->dr);
}

int numarFrunzeLitM(nod * rad){
  if(rad == NULL)return 0;
  if((rad ->st == NULL) && (rad->dr == NULL))
    if(isupper(rad->info))
      return numarFrunzeLitM(rad->st) + numarFrunzeLitM(rad->dr) + 1;
  return numarFrunzeLitM(rad->st) + numarFrunzeLitM(rad->dr);
}

int prodAscii(nod * rad){
  if(!rad)
    return 1;
  else{
    if( (int)rad->info % 2 == 1)
      return (int)rad->info * prodAscii(rad->st) * prodAscii(rad->dr);
    return  prodAscii(rad->st) * prodAscii(rad->dr);
  }
}

int maxim3(int a, int b, int c){
  if(b > a)a = b;
  if(c > a)a = c;
  return a;
}

int Maxim(nod * rad){
  if(rad == NULL)
    return 0;
  else
    return maxim3((int)rad->info,Maxim(rad->st),Maxim(rad->dr));
}

int minim3(int a, int b, int c){
  if(b < a)a = b;
  if(c < a)a = c;
  return a;
}

int Minim(nod * rad){
  if(rad == NULL)
    return 0;
  if(strchr("EAIOUaeiou",rad->info))
    return minim3((int)rad->info,Minim(rad->st),Minim(rad->dr));
  return minim3((int)rad->info,(int)'A'-1,(int)'A'-1);
}

void afisSgFiu(nod* rad){
  if(rad != NULL){
    if(rad->st == NULL && strchr("EAIOUaeiou",rad->info)==0)
      cout<<rad->info<<' ';
    else if(rad->dr == NULL && strchr("EAIOUaeiou",rad->info)==0)
      cout<<rad->info<<' ';
    afisSgFiu(rad->st);
    afisSgFiu(rad->dr);
  }
}


int main(){
  nod * rad = NULL;
  citire(rad);
  cout<<"\nAfisare RSD\n";
  afisVocRSD(rad);
  cout<<"\nAfisare SDR\n";
  afisVocSDR(rad);
  cout<<"\nAfisare numar de consoane : "<<numarCons(rad)<<'\n';
  cout<<"\nAfisare suma ASCII : "<<sumaAscii(rad)<<'\n';
  cout<<"\nAfisare nr frunze : "<<numarFrunze(rad)<<'\n';
  cout<<"\nAfisare nr frunze cu litere mari: "<<numarFrunzeLitM(rad)<<'\n';
  cout<<"\nAfisare produs ascii impar: "<<prodAscii(rad)<<'\n';
  cout<<"\nAfisare maxim ASCII : "<<Maxim(rad)<<'\n';
  cout<<"\nAfisare minim par ASCII : "<<Minim(rad)<<'\n';
  cout<<"\nAfisare vocale din subarbore drept :\n";
  afisVocRSD(rad->dr);
  cout<<"\nAfisare consoane 1 singur fiu :\n";
  afisSgFiu(rad);
  return 0;
}
