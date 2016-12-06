#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

FILE * in = fopen("pb.in","r");
FILE * out = fopen("pb.txt", "w");

char cuv[21], x, st[21];
int lg=0;

void citire(){
  do{
    fscanf(in,"%c",&x);
    if(!strchr(cuv,x)){
      cuv[lg++]=x;
    }
    cuv[lg]='\0';
  }while(x!=' ');
  cuv[lg-1]='\0';
}

bool validare(int k){
  if(k>0 && strchr("aeiou",st[k]) && strchr("aeiou",st[k-1])){
    return false;
  }
  if(k>0 && !strchr("aeiou",st[k]) && !strchr("aeioua",st[k-1])){
    return false;
  }
  for(int i=0;i<k;i++)
    if(st[k]==st[i])
      return false;
  return true;
}

void afisare(){
  fprintf(out,"%s\n",st);
}

void bkt(int k){
  for(int i=0;i<strlen(cuv);i++){
    st[k]=cuv[i];
    if(validare(k) && k < strlen(cuv)){
      if(k==(strlen(cuv)-1))
        afisare();
      else
        bkt(k+1);
    }
  }
}

int main(){
  citire();
  bkt(0);
  return 0;
}
