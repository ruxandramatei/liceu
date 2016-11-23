#include <iostream>
#include <fstream>

using namespace std;

int s, p;
int st[100];
bool v[100];

ifstream in("pb.in");
ofstream out("pb.txt");

void citire(){
  in>>s>>p;
}

void afisare(){
  for(int i=1;i<=p;i++)
    out<<st[i]<<' ';
  out<<'\n';
}

int suma;

bool validare(int k){
  suma = 0;
  for(int i=1;i<=k;i++)
    suma+=st[i];
  if(suma<=s)
    return true;
  return false;
}
int paritate;

void bkt(int k){
  for(int i=1;i<=s-p;i++){
    if(v[i]==false){
      st[k]=i;
      v[i]=true;

      if(k==1)
        paritate=st[k]%2;

      if((k%2==1 && paritate==st[k]%2)||k%2==0){
        if(validare(k)){
          if(k==p && suma==s)
            afisare();
          if(k<p)bkt(k+1);
        }
      }
      v[i]=false;
    }
  }
}

int main(){
  citire();
  bkt(1);
  return 0;
}
