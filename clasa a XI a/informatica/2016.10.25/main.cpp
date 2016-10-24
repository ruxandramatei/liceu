#include <iostream>
#include <fstream>

using namespace std;

ifstream in("spectacol.in");
ofstream out("spectacol.txt");

struct spectacol{
  int start , time;
  int poz;
}v[100];

int n;

void creare(){
  in>>n;
  for(int i = 1 ; i <=n ;i++){
    in>>v[i].start>>v[i].time;
    v[i].poz = i;
  }
}

void sortare(){
  for(int i =1 ;i < n ;i++){
    for(int j = i+1 ; j<=n ; j++){
      if(v[i].time+v[i].start>v[j].time+v[j].start){
        v[0]=v[i];
        v[i]=v[j];
        v[j]=v[0];
      }
    }
  }
}

void Greedy(){
  sortare();
  int u=1;
  out<<v[u].poz<<' ';
  for(int i = 2 ; i <=n ; i++){
    if(v[i].start >= v[u].start+v[u].time){
      out<<v[i].poz<<' ';
      u=i;
    }
  }
}

int main(){

  creare();
  Greedy();

  return 0;
}
