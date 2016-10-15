#include "declarare.cpp"
void stergerePrimulNod(ruta * & prim){
  ruta  * deSters = prim;
  prim = prim->urm;
  delete deSters;
}
