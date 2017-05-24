#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b){
  if(a < b){
    int temp = a;
    a = b;
    b = temp;
  }

  int r;
  while(b != 0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main(){
    int t;
    in>>t;
    for(int i=1;i<=t;i++){
      int x, y;
      in>>x>>y;
      out<<euclid(x,y)<<'\n';
    }
    return 0;
}
