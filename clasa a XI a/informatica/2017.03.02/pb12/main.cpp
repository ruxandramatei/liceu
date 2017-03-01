#include <iostream>
#include <fstream>

using namespace std;

ifstream in("gradmax.in");
ofstream out("gradmax.out");

int m, v[101], a[101][101];
int maxim=0;

void citire(){
    in>>m;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0){
            a[x][y]=a[y][x]=1;
            v[x]++;
            v[y]++;
            if(v[x]>maxim || v[y]>maxim)
                maxim = max(v[x],v[y]);
        }
    }
}

int main(){

    int nr=0;
    citire();
    for(int i=1;i<=m;i++)
        if(v[i]==maxim)
            nr++;
    out<<nr<<' ';
    for(int i=1;i<=m;i++)
        if(v[i]==maxim)
            out<<i<<' ';
    return 0;
}
