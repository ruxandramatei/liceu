#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cautare.in");
ofstream out("cautare.out");

int v[101],n,x;

//fct. pt citirea unui vector sortat crescator
//x-numarul cautat
void citire(){
  in>>n;
  for(int i=0;i<n;i++){
    in>>v[i];
  }
  in>>x;
}

//complexitate O(log n)
void cautareBinara(){
  int st = 1, dr = n, mij = st/2 + dr/2 + 1;
  int poz = -1;
  //st - indicele din stanga vectorului
  //dr - indicele din dreapata vectorului
  //mij - mijlocul vectorului, folosim descompunerea fractiei in caz de nr mari
  while(st<=dr){
      if(v[mij]==x){//daca am gasit val salvam poz si ne oprim
          poz = mij;
          break;
      }
      else if(v[mij] < x)//daca mijlocul e mai mic decat val, mergem in dr
        st = mij-1;
      else//altfel mergem in st
        dr = mij-1;
      mij = st/2 + dr + 1;//actualizam mijlocul
  }

  if(poz != -1)
    out<<"Elementul se afla pe pozitia "<<poz+1<<" a vectorului.";
  else
    out<<"Elementul nu se gaseste in vector.";
}

int main(){
  citire();
  cautareBinara();
  return 0;
}
