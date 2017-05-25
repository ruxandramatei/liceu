#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid3.in");
ofstream out("euclid3.out");

void euclid(int a, int b,int &d, int &x, int &y){
  if(b==0){
    d = a;
    x=1;
    y=0;
  }
  else{
    int x0,y0;
    euclid(b,a%b,d,x0,y0);
    x = y0;
    y = x0 - (a/b)*y0;
  }
}

int main(){
  int n;
  in>>n;
  for(int i=1;i<=n;i++){
    int x = 0, y= 0,d=0;
    int a, b , c;
    bool ok = false;
    in>>a>>b>>c;

    euclid(a,b,d,x,y);
    x = x*(c/d);
    y= y*(c/d);
    if(c%d)
      out<<"0 0\n";
    else out<<x<<' '<<y<<'\n';
  }
  return 0;
}
