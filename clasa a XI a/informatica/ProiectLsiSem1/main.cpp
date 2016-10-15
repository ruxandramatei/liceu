#include <iostream>
#include <algorithm>
#include "Operatii.h"

using namespace std;

ruta * primul, *ultimul ;

void ordonareInsertKilom(ruta * & prim ,ruta * & ultim ,ruta * &deAdaugat){
  if(prim == NULL){
    inserareInceput(prim,ultim,deAdaugat);
    return;
  }
  if(prim->distanta >= deAdaugat->distanta){
    inserareInceput(prim,ultim,deAdaugat);
    return;
  }
  if(ultim->distanta <= deAdaugat->distanta){
    adaugareSfarsit(prim,ultim,deAdaugat);
    return;
  }
  ruta * i;
  for( i = prim ; i->urm!= NULL && i->urm->distanta < deAdaugat->distanta; i = i->urm);
  deAdaugat->urm = i->urm;
  i->urm = deAdaugat;
}

int main(){
  ruta * RutaT;
  int optiune;
  cout <<"Salut , utilizatorule !\n";
  cout<<"Eu efectuez operatii asupra unor rute de tren .\n";
  cout<<"Te rog sa scrii rutele in fisierul de intrare TEXT.in\n";
  cout<<"Iti voi enumera operatiile pe care le poti face asupra acestor rute\n";
  cout<<" iar tu iti alegi optiunea :";
  cout<<"1.Citire lista si crearea ei ordonata din citire\n";
  cout<<"2.Inserarea unei noi rute la inceputul listei\n";
  cout<<"3.Inserarea unei noi rute la sfarsitul listei\n";
  cout<<"4.Inserarea unui nou nod dupa un anumit pret cerut de tine si citit in terminal\n";
  cout<<"5.Inserarea unui nou nod inainte de o anumita distanta citita de tine in terminal\n";
  cout<<"6.Stergerea primei rute din lista \n";
  cout<<"7.Stergerea ultimei rute din lista \n";
  cout<<"8.Stergerea dupa un pret citit de tine \n";
  cout<<"9.Afisare rute \n";
  cout<<"10.Ordonarea si afisarea rutelor\n";
  cout<<"11.EXIT\n";

  do{
    cout<<"citeste optiunea\n";
    cin>>optiune;
    switch (optiune) {
      case 1:{
        cout <<"cititi numarul rutelor in terminal , iar pe ele le scrieti in fisier\n";
        int nr;
        cin>>nr;
        for(int i = 0 ; i < nr ; i++ ){
          RutaT = new ruta;
          citire(RutaT);
          ordonareInsertKilom(primul,ultimul,RutaT);
        }
        cout <<"Rutele citite vor fi afisate in IESIRE.txt";
        for(ruta * i = primul ; i ; i = i->urm){
          afisare(i);
          cout<<"\n";
        }
        break;
      }
      case 2:{
        cout<<"Cititi o noua ruta\n";
        RutaT = new ruta;
        citire(RutaT);
        inserareInceput(primul,ultimul,RutaT);
        break;
      }
      case 3:{
        cout<<"Cititi o noua ruta\n";
        RutaT = new ruta;
        citire(RutaT);
        adaugareSfarsit(primul,ultimul,RutaT);
        break;
      }
      case 4:{
        cout<<"Cititi o noua ruta\n";
        RutaT = new ruta;
        citire(RutaT);
        cout<<"Cititi pretul \n";
        int pr ;
        cin>>pr;
        inserareDupa(primul,ultimul,RutaT,pr);
        break;
      }
      case 5:{
        cout<<"Cititi o noua ruta\n";
        RutaT = new ruta;
        citire(RutaT);
        cout<<"Cititi distanta\n";
        int pr ;
        cin>>pr;
        inserareDupa(primul,ultimul,RutaT,pr);
        break;
      }
      case 6:{
        stergerePrimulNod(primul);
        break;
      }
      case 7:{
        stergereUltimulNod(primul,ultimul);
        break;
      }
      case 8:{
        cout<<"Cititi pretul care vreti sa-l stergeti:\n";
        int pr;
        cin>>pr;
        stergereCunData(pr,primul,ultimul);
        break;
      }
      case 9:{
        afisareLista(primul);
        break;
      }
      case 10:{
        ordonarePret(primul);
        cout<<"Lista ordonata dupa pret este :\n";
        afisareLista(primul);
        break;
      }
    }
  }while(optiune!=11);

  return 0;
}
