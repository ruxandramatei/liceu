#include <iostream>
#include <fstream>

using namespace std;

ifstream in("bipartit1.in");
ofstream out("bipartit1.out");

int a[101][101], n;

void citire(){

    int m;
    in>>n>>m;
    int x, y;
    for(int i=1;i<=m;i++){
        in>>x>>y;
        a[x][y]=a[y][x]=1;
    }

}

int viz[101], c[101];
bool ok;

void bf(){

    int p , u ;
    p=u= 1;
    c[1]=1;
    viz[1]=1;
    ok=true;

    while(p<=u){

        for(int i=1;i<=n;i++)
        {
            if(a[c[p]][i]==1){
                    if(viz[i]==0){
                        viz[i]=3-viz[c[p]];
                        c[++u]=i;
                    }
                    else if(viz[c[p]]==viz[i])
                        ok= false;
            }
        }

        p++;
    }

}


int main()
{
    citire();
    c[1]=1;
    viz[1]=1;
    bf();
    if(ok==true)
        out<<"DA\n";
    else
        out<<"NU\n";
    if(ok==true)
    {
        for(int i=1;i<=n;i++)
        if(viz[i]==1)
            out<<i<<' ';
        out<<'\n';
        for(int i=1;i<=n;i++)
            if(viz[i]==2)
                out<<i<<' ';

    }
    return 0;
}
