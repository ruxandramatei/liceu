#include <iostream>
#include <fstream>

using namespace std;

ifstream in("graf.in");
ofstream out("izolate.out");

int n, a[11][10],v[11],k;

void citire(){

    in>>n;
    for(int i=1;i<=n;i++){
        bool ok = true;
        for(int j=1;j<=n;j++){
            char x;
            in>>x;
            a[i][j]=a[j][i]=x-'0';
            if(a[i][j]==1)
                ok=false;
        }
        if(ok==true)
            v[++k]=i;

    }

}

void rezolvare(){

    if(k==0){
        out<<"Nu exista astfel de noduri";
        return;
    }
    int j=1;
    for(int i=1;i<=k;i++){
        out<<v[i]<<' ';
        if(j==i){
            j=1;
            out<<'\n';
        }
        else j++;
    }

}

int main(){

    citire();
    rezolvare();
    return 0;

}
