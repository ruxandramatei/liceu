
#include <iostream>

using namespace std;

struct ruta{
  int pret;
  char dataCalatorie[20];
  char tren[10],statiePlecare[20],statieSosire[20];
  char oraPlecare[6],oraSosire[6],operatorFeroviar[20];
  int distanta;
  char rezervare[20];
  ruta * urm;
};
