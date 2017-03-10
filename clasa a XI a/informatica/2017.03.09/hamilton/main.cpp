#include <iostream>
#include <fstream>

using namespace std;

ifstream in("hamilton.in");
ofstream out("hamilton.out");

int a[101][101], n;

void citire(){

    in>>n;
    int x, y;
    while(in>>x>>y){
        if(a[x][y]==0)
            a[x][y]=a[y][x]=1;
    }

}

int st[101],c[101];
bool ok =false;
int rez[101];

void bkt(int k){

    for(int i=2;i<=n;i++)
        if(c[i]==0)
        {
            c[i]=1;
            st[k]=i;
            if(a[i][st[k-1]]==1){
                if(k==n && a[st[1]][st[k]]==1){
                        for(int i=1;i<=n;i++)
                            rez[i]=st[i];
                        ok=true;
                    }
                else if(k<n)
                    bkt(k+1);
            }

            c[i]=0;
        }


}

int main()
{
    citire();
    st[1]=1;
    c[1]=1;
    bkt(2);
    out<<ok<<'\n';
    for(int i=1;i<=n;i++)
        out<<rez[i]<<' ';
    out<<rez[1];
    return 0;
}
