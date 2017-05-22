#include <iostream>
#include <fstream>

using namespace std;

ifstream in("descompunere.in");
ofstream out("descompunere.out");

//Algoritmul consta in repetarea impartirii unui deimpartit d la un factor prim
//posibil f, atata timp cat deimpartitul e diferit de 1.
//Initial deimpartitul este x, iar primul factor pos e 2

int main(){
  int x,d,f,p,nr;
  in>>x;
  d = x;
  f=2;
  p=0;//puterea la care apare factorul f;
  while(d>1){
    p=0;//initial puterea fact e 0
    while(d%f==0){
      p++;
      d/=f;
    }
    if(p!=0)//daca factorul e valabil afisez impreuna cu puterea sa
      out<<f<<' '<<p<<'\n';
    if(f==2)
      f++;
    else
      f+=2;
  }
  return 0;
}
