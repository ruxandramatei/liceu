#include "declarare.cpp"
void adaugareSfarsit(ruta * & prim, ruta * & ultim , ruta * &deAdaugat){
  if(prim==NULL)prim = deAdaugat;
  else{
    deAdaugat->urm=NULL;
    ultim->urm = deAdaugat;
  }
  ultim = deAdaugat;
}
