#include <iostream>
#include <fstream>

using namespace std;

ifstream in("gradmax.in");
ofstream out("gradmax.out");

int m, v[101], a[101][101],n;

void citire(){
    in>>m>>n;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0){
            a[x][y]=a[y][x]=1;
            v[x]++;
            v[y]++;

        }
    }
}

int main(){

    int nr=0;
    citire();
    out<<"Varfurile izolate sunt :";
    for(int i=1;i<=m;i++)
        if(v[i]==0)
           out<<i<<' ';
    out<<"\nVarfurile de grad impar sunt:";
    for(int i=1;i<=m;i++)
        if(v[i]%2==1)
           out<<i<<' ';
    return 0;
}
