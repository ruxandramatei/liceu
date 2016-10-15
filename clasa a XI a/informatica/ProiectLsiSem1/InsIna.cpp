//inserarea inaintea primei distante k a unei noi rute
#include "declarare.cpp"
void inserareInainte( ruta * & prim ,ruta * &ultim,ruta * & deAdaugat,int  k){
   if (k==prim->distanta){
     deAdaugat->urm = prim;
     prim = deAdaugat;
     return;
   }
   for(ruta * i = prim ;i->urm;i= i->urm){
     if(i->urm->distanta == k){
       deAdaugat->urm = i->urm;
       i->urm = deAdaugat;
     }
   }
}
