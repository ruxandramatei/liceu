#include "declarare.cpp"
void inserareInceput(ruta * & prim, ruta * & ultim ,ruta * &deAdaugat){
   if(prim==NULL){
     prim = ultim = deAdaugat;
   }
   else{
     deAdaugat->urm = prim;
     prim = deAdaugat;
   }
}
