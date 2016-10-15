//inserarea dupa primul pret k a unei noi rute
#include "declarare.cpp"
void inserareDupa(ruta * & prim , ruta * & ultim ,ruta * & deAdaugat,int k){
   if (k==ultim->pret){
     ultim->urm = deAdaugat;
     ultim = deAdaugat;
   }
   for(ruta * i = prim ;i;i= i->urm){
     if(i->pret == k){
       deAdaugat->urm = i->urm;
       i->urm = deAdaugat;
     }
   }
}
