#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.txt");

int n;
int st[10];

//citire numar
void citire(){
  in>>n;
}

//verificam daca numarul se repeta in stiva
// returnand true sau false
bool validare(int k){
  for(int i = 1; i < k; i++)
      if(st[i] == st[k])
        return false;
  return true;
}

//verificam daca numarul e solutie
//el fiind solutie atunci cand stiva e plina
bool solutie(int k){
  if(k == n)
    return true;
  return false;
}

void afisare(){
  out<<"{ ";
  for(int i = 1; i <= n; i++)
    out<<st[i]<<' ';
  out<<"}\n";
}

void bkt(int k){
  for(int i = 1; i<= n; i++){
      st[k]=i;
      //daca numarul nu se repeta in stiva
      if(validare(k)){
        //daca am ajuns la o solutie afisam
        if(solutie(k))
          afisare();
        //altfel mai adaugam  in stiva
        else
          bkt(k+1);
      }
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
