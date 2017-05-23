#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmmdcScaderi.in");
ofstream out("cmmdcScaderi.out");

//ALGORITMUL LUI NICOMAHUS (metoda scaderilor repetate)

int main(){
  int x, y;
  int temp1,temp2;

  in>>x>>y;
  temp1 = x;
  temp2 = y;

  while(temp1 != temp2){
    if(temp1 > temp2)
      temp1 = temp1 - temp2;
    else
      temp2 = temp2 - temp1;
  }

  out<<"CMMDC celor 2 numere este : "<<temp1;
  out<<"\nCMMMC celor 2 numere este : "<<(x*y)/temp1;
}
