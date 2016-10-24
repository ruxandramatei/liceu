#include <iostream>

using namespace std;

struct nod{
  int info;
  nod * st , * dr;
};

void creare(nod * & rad){
  int x;
  cin>>x;
  if(x==0)
    rad=NULL;
  else{
    rad = new nod;
    rad->info = x;
    creare(rad->st);
    creare(rad->dr);
  }
}

void RSD(nod * rad){
  if(rad){
    cout<<rad->info<<' ';
    RSD(rad->st);
    RSD(rad->dr);
  }
}

void ogl(nod * rad , nod * & cre){//MERGE
  if(!rad)cre=NULL;
  if(rad){
    cre = new nod;
    cre->info = rad->info;
    ogl(rad->st,cre->dr);
    ogl(rad->dr,cre->st);
  }
}

int v[100],k ,ino[100];

void vec(nod * rad){
  if(rad){
    v[++k]= rad->info;
    vec(rad->st);
    ino[k-1]=rad->info;
    vec(rad->dr);
  }
}

void echil(nod * &rad,int st,int dr){
  if(st <=  dr){
    int m = (st + dr)/2;
    rad = new nod;
    rad->info = v[m];
    echil(rad->st,st,m-1);
    echil(rad->dr,m+1,dr);
  }
  else rad = NULL;
}

int cauta(int x,int p , int q){
  for(int i = p  ;i <= q ; i++){
    if(ino[i]==x)return i;
  }
}

void CreAre(nod * & rad ,int c ,int i , int j ){
  if(i>j)rad=NULL;
  else{
    int m = cauta(v[c],i,j);
    rad= new nod;
    rad->info = v[c++];
    CreAre(rad->st,c,i,m-1);
    CreAre(rad->dr,c,m+1,j);
  }
}

int main(){
  nod * rad = new nod ;
  creare(rad);
  vec(rad);
  CreAre(rad,0,1,k);
  RSD(rad);
  return 0;
}
