#include <iostream>
#include <fstream>

using namespace std;

ifstream in("sortaret.in");
ofstream out("sortaret.out");

typedef struct nod{
  int val;
  nod *urm;
}AD;

AD *v[50001];
int grad[50001], n, m;
int queue[50001];

void alocareDinam(){
  for(int i=1;i<=n;i++){
    v[i] = new AD;
    v[i]->urm = NULL;
  }
}

void citire(){
  in>>n>>m;
  alocareDinam();
  for(int i=1;i<=m;i++){
    int a, b;
    in>>a>>b;
    AD *x = new AD;
    x->val = b;
    x->urm = v[a]->urm;
    v[a]->urm = x;
    grad[b]++;
  }
  //ok
}

void initializareCoada(){
  for(int i=1;i<=n;i++)
    if(grad[i]==0)
      queue[++queue[0]]=i;
}


void afisare(){
  for(int i=1;i<=n;i++)
    out<<queue[i]<<' ';
}

void solve(){
  initializareCoada();
  for(int i = 1;i<=queue[0];i++){
    int x = queue[i];
    AD *temp = new AD;
    temp = v[x]->urm;
    while(temp!=NULL){
      grad[temp->val]--;
      if(grad[temp->val]==0)
        queue[++queue[0]]=temp->val;
      temp = temp->urm;
    }
  }
}

int main(){
  citire();
  solve();
  afisare();
  return 0;
}
