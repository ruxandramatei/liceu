#include "declarare.cpp"
void stergereCunData(int pret1 , ruta * &prim , ruta * & ultim){
  if(prim->pret == pret1){
    ruta  * deSters = prim;
    prim = prim->urm;
    delete deSters;
  }
  for(ruta * i =prim ; i ->urm ;){
    if(i->urm->pret == pret1){
      if(i->urm->urm == NULL){
        ruta * deSters = i->urm;
        i->urm= NULL;
        ultim = i;
        delete deSters;
      }
      else{
        ruta * deSters = i->urm;
        i->urm = i->urm->urm;
        delete deSters;
      }
    }
    else i = i->urm;
  }
}
