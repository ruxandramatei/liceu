#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int a[101][101],n,m;
bool ok;

void citire(){
  in>>n>>m;
  for(int i=1;i<=n;i++){
    int x,y;
    in>>x>>y;
    a[x][y]=1;
  }
}

void bf(int x){

  int viz[101];

  for(int i=0;i<=n;i++)
    viz[i]=0;

  int c[101],u,p;
  u=p=1;
  c[1]=x;
  viz[x]=1;
  while(p<=u){
    x=c[p++];
    for(int i=1;i<=n;i++){
        if(viz[i]==0 && a[i][x]==1){
          c[++u]=i;
          viz[i]=1;
          viz[0]++;
        }
    }
  }
  if(viz[0]==(n-1))
    ok=true;

}

int main(){
  citire();
  ok=false;
  for(int i=1;i<=n;i++)
  {
    bf(i);
    if(ok==true)
      {
        out<<i;
        break;
      }
  }
  if(ok==false)
    out<<"NU EXISTA";
  return 0;
}
