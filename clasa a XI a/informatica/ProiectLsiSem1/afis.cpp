#include "declarare.cpp"
#include <fstream>
ofstream out("IESIRE.txt");
void afisare(ruta * RutaT){
    out<<RutaT->pret<<' ';
    out<<RutaT->dataCalatorie<<' ';
    out<<RutaT->tren<<' ';
    out<<RutaT->statiePlecare<<' ';
    out<<RutaT->statieSosire<<' ';
    out<<RutaT->oraPlecare<<' ';
    out<<RutaT->oraSosire<<' ';
    out<<RutaT->distanta<<' ';
    out<<RutaT->operatorFeroviar<<' ';
    out<<RutaT->rezervare<<'\n';
}
