#include "declarare.cpp"
void stergereUltimulNod(ruta * & prim , ruta * & ultim ){
  ruta * i ;
  for(i = prim ; i->urm->urm ; i = i->urm);
  ruta * deSters = i->urm;
  i->urm = NULL;
  ultim = i;
  delete deSters;
}
