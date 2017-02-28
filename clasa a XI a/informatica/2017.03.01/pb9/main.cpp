#include <iostream>
#include <fstream>
#define DIM 100

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[DIM][DIM], n ;

struct NOD{
  int eticheta, grad;
}v[10];

void citire(){

  in>>n;
  bool ok=true;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; j++){
        in>>a[i][j];
        if(i==j && a[i][j]==1)
            {
                ok=false;
                break;
            }
        }
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; j++)
    if(a[i][j]!=a[j][i]){
            ok=false;
            break;
    }

    if(ok==false)
        out<<"MATRICEA NU E GRAF!";
    else
        out<<"E OK!";
}


int main(){

    citire();
    return 0;

}
