#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("lant1.in");
ofstream fout("lant1.out");

int n,p,q,r,a[101][101],st[101],stop,okr;

void citire()
{
    fin>>n>>p>>q>>r;
    int i,j;
    while (fin>>i>>j)
    a[i][j]=a[j][i]=1;
}

int valid(int k)
{
    if (!a[st[k]][st[k-1]]) return 0;
    if(k>2)
    {
        for(int i=1;i<=k-2;i++)
            if(st[k]==st[i])
                if (st[k-1]==st[i-1] ||st[k-1]==st[i+1]) return 0;
    }
    return 1;
}

void afis(int k)
{
    fout<<k<<"\n";
    for (int i=1; i<=k; ++i) fout<<st[i]<<' ';
    fout<<"\n";
}

int verif(int k)
{
    for(int i=1;i<=k;++i)
    if(st[i]==r) return 1;
    return 0;
}
void BKT(int k)
{
    for (int i=1; i<=n && stop ==0; ++i)
    {
        st[k]=i;
        if (valid(k))
        {
            a[st[k]][st[k-1]]=a[st[k-1]][st[k]]=0;
            if (st[k]==q)
            {
                if (verif(k))
                {
                    if (!stop) afis(k);
                    stop=1;
                }
            }
            if (k<=2*n) BKT(k+1);

        }
    }
}
int main()
{
citire();
st[1]=p;
BKT(2);
return 0;
}
