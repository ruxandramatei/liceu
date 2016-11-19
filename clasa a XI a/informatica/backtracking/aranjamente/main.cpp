/**Conditii aranjamente:
    *1 <= st[k] <= n
    *st[k] != st[i], i e {1, k-1}
    *k == m
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n, m, st[10];
//n - numarul total de cifre
//m - numere luate cate m

void citire(){
  in>>n>>m;
}

//verificam daca numarul se repeta in stiva
//returnand true daca nu se repeta sau false altfel
bool validare(int k){
  for(int i = 1; i < k; i++)
    if(st[i] == st[k])
      return false;
  return true;
}

//verificam daca stiva e plina
bool solutie(int k){
  if(k == m)
    return true;
  return false;
}

void afisare(){
  out<<"{ ";
  for(int i = 1; i <= m; i++)
    out<<st[i]<<' ';
  out<<"}\n";
}

void bkt(int k){
  for(int i = 1; i <= n; i++){
    st[k] = i;
    //daca numarul introdus nu se repeta
    if(validare(k))
      //daca am ajuns la solutie k == m , afisam
      if(solutie(k))
        afisare();
      //altfel mai adaugam in stiva
      else
        bkt(k+1);
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
