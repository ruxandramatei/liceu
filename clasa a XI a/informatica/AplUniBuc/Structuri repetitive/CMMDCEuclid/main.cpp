#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmmdcEuclid.in");
ofstream out("cmmdcEuclid.out");

int main(){
  int x, y, r;
  in>>x>>y;

  if(x<y){
    int temp = x;
    x = y;
    y = temp;
  }

  do{
    r = x % y;
    x = y;
    y = r;
  }while(y!=0);

  out<<"Cel mai mare divizor comun este : "<<x;
  
  return 0;
}
