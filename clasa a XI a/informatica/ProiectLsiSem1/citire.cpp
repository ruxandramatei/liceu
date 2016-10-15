#include "declarare.cpp"
#include <fstream>
ifstream in("TEXT.in");
void citire(ruta * RutaT){
  in>>RutaT->pret;
  in>>RutaT->dataCalatorie;
  in>>RutaT->tren;
  in>>RutaT->statiePlecare;
  in>>RutaT->statieSosire;
  in>>RutaT->oraPlecare;
  in>>RutaT->oraSosire;
  in>>RutaT->distanta;
  in>>RutaT->operatorFeroviar;
  in>>RutaT->rezervare;
  RutaT->urm=NULL;
}
