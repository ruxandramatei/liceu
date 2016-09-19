#include <iostream>
#include <string.h>

using namespace std;

struct nod{
  char maj;
  int nrAp;
  nod *urm;
};

int frecv[100];

void rezolvare(){
  char s[255];
  cin.getline(s,254);
  for(int i = 0 ; s[i]!='\0' ; i++){
    if(s[i] >= 'A' && s[i] <= 'Z')frecv[s[i]-'0']++;
  }
  nod * prim = NULL;
  nod * ultim = NULL;
  for(int i = 0 ; i <='Z'-'0' ; i++){
    if(frecv[i]>=2){
      nod * deAdaugat = new nod;
      deAdaugat->maj = (char)i + '0';
      deAdaugat->nrAp = frecv[i];
      deAdaugat->urm = NULL;
      if(prim == NULL)prim = ultim = deAdaugat;
      else{
          ultim->urm = deAdaugat;
      }
      ultim = deAdaugat;
    }
  }

  while(prim!=NULL){
    cout<<"Caracterul este :"<<prim->maj<<" si apare de "<<prim->nrAp<<" ori\n";
    prim = prim->urm;
  }
}



int main(){
  rezolvare();
  return 0;
}
