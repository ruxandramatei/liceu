#include "declarare.cpp"
void afisare(ruta * RutaT){
    cout<<RutaT->pret<<' ';
    cout<<RutaT->dataCalatorie<<' ';
    cout<<RutaT->tren<<' ';
    cout<<RutaT->statiePlecare<<' ';
    cout<<RutaT->statieSosire<<' ';
    cout<<RutaT->oraPlecare<<' ';
    cout<<RutaT->oraSosire<<' ';
    cout<<RutaT->distanta<<' ';
    cout<<RutaT->operatorFeroviar<<' ';
    cout<<RutaT->rezervare<<'\n';
}
