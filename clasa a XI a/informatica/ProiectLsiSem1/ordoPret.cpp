#include "declarare.cpp"
void ordonarePret(ruta * & primul){
  for(ruta * i = primul ; i ->urm ; i = i->urm){
    for(ruta * j = i->urm ; j ; j= j->urm){
      if(i->pret>j->pret){
        swap(i->pret,j->pret);
        swap(i->dataCalatorie,j->dataCalatorie);
        swap(i->tren,j->tren);
        swap(i->statiePlecare,j->statiePlecare);
        swap(i->statieSosire,j->statieSosire);
        swap(i->oraPlecare,j->oraPlecare);
        swap(i->oraSosire,j->oraSosire);
        swap(i->distanta,j->distanta);
        swap(i->operatorFeroviar,j->operatorFeroviar);
        swap(i->rezervare,j->rezervare);
      }
    }
  }
}
