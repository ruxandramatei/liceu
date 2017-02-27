#include <iostream>
#include <fstream>

using namespace std;

ifstream in("graf.in");
ofstream out("graf.out");

int m, a[101][101],v[101];
int nr=0;

int suma(int L){

    int s=0;
    for(int i=1; i<=m; i++)
        s+=a[L][i];
    return s;

}

void gradMinMax(int &miki, int &mini){

    mini=suma(1);
    v[1]=mini;
    miki = v[1];
    for(int i=2;i<=m;i++){
        int a = suma(i);
        v[i]=a;
        if(mini>a)
            mini = a;
        if(miki<a)
            miki = a;
    }
}

void citire(){
    in>>m;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0 ){
            a[x][y]=a[y][x]=1;
        }
    }
}

void rezolvare(){
    int mini , miki;
    gradMinMax(miki,mini);
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if((v[i]==miki && v[j]==mini)||(v[j]==miki && v[i]==mini))
                if(a[i][j]==0){
                    a[i][j]=a[j][i]=1;
                }
                else
                    a[i][j]=a[j][i]=0;
        }
    }
     for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++)
                out<<a[i][j]<<' ';
            out<<'\n';
    }

}

int main(){

    citire();
    rezolvare();
    return 0;
}
