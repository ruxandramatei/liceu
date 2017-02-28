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
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            in>>a[i][j];
            v[i]++;
        }
        if(v[i]>maxim)
            maxim= v[i];
    }
}

int main(){

    int nr=0;
    citire();
    for(int i=1;i<=m;i++)
        if(v[i]==maxim)
            out<<i<<' ';
    return 0;
}
