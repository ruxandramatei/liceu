#include <iostream>
#include <fstream>

using namespace std;

ifstream in("interclasare.in");
ofstream out("interclasare.out");

//Pornind de la 2 vectori x,y ordonati crescator sa formam
//un vector z care sa contina elementele celor 2 vectori in ordine crescatoare

void citire(int v[101],int &dim){
  in>>dim;
  for(int i=1;i<=dim;i++)
    in>>v[i];
}

int main(){
  int x[101], y[101], z[101];
  int lgx, lgy, lgz = 0;

  citire(x, lgx);
  citire(y,lgy);

  //interclasam vectorii
  int i = 1, j = 1;
  while(i<=lgx && j<=lgy){
    if(x[i] < y[j]){//daca val x e mai mica punem in z x
      z[++lgz] = x[i];
      i++;
    }
    else{//altfel punem y in z
      z[++lgz] = y[j];
      j++;
    }
  }

  while(i <= lgx)
    z[++lgz] = x[i++];

  while(j <= lgy)
    z[++lgz] = y[j++];

  out<<"Lungimea vectorului rezultat este : "<<lgz<<'\n';
  out<<"Vectorul rezultat din interclasare este : ";
  for(int i=1;i<=lgz;i++)
    out<<z[i]<<' ';
  return 0;
}
