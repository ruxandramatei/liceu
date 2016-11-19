/**Conditii combinari:
    *st[k-1]+1 <= st[k] <= n-m+
    *k == m
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, m, st[10];
//n - nr de numere
//m - nr luate cate m

void citire(){
  in>>n>>m;
}

void afisare(){
  out<<"{ ";
  for(int i = 1; i <= m; i++)
    out<<st[i]<<' ';
  out<<"}\n";
}

//daca stiva e plina returnam true, altfel false
bool solutie(int k){
  if(k == m)
    return true;
  return false;
}

void bkt(int k){
  for(int i = st[k-1]+1; i<= n-m+k; i++){
    st[k] = i;
    //daca stiva e plina afisam , altfel mai adaugam
    if(solutie(k))
      afisare();
    else
      bkt(k+1);
  }
}

int main(){
  citire();
  //st[0]=0;
  bkt(1);
  return 0;
}
