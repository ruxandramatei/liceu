#include <iostream>
#include <fstream>

#define inf 100000

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,k;

void citire(){
  in>>n>>k;
  int x,y,c;
  while(in>>x>>y>>c)
    a[x][y]=c;

}

void dijkstra(int x0){
  int viz[101],d[101];
  int minim , pozMinim;

  for(int i=1;i<=n;i++){
    viz[i]=0;
    if(a[x0][i]!=0)
      d[i]=a[x0][i];
    else if(i==x0){//marcam punctul de plecare
      viz[i]=1;
      d[i]=0;
    }
    else
      d[i]=inf;
  }
  //ok;
  int ok=1;//Cand in coada avem valori diferite de inf
  while(ok==1){
    //Cautam minimul in valorile neselectate
    minim=inf;
    for(int i=1;i<=n;i++)
      if(minim>d[i] && viz[i]==0){
        minim=d[i];
        pozMinim=i;
      }
  //am gasit val minima nemarcata, verificam daca e dif de inf
    if(minim==inf)ok=0;
    else {
      viz[pozMinim]=1;
      for(int i=1;i<=n;i++)
        if(viz[i]==0 &&a[pozMinim][i]!=0&& ((a[pozMinim][i]+d[pozMinim])<d[i]))
          d[i]=a[pozMinim][i]+d[pozMinim];

    }
  }
  for(int i=1;i<=n;i++){
    if(d[i]!=inf)
      out<<d[i]<<' ';
    else
      out<<"-1 ";
  }
}



int main(){
  citire();
  dijkstra(k);
  return 0;
}
