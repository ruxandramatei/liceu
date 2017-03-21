#include <iostream>

using namespace std;

void ProdusMic(NrMare x, int n)
{

    int i,t=0;
    for(i=1;i<=x[0];i++,t/=10)
    {
        t+=x[i]*n;
        x[i]=t%10;
    }

    for(;t;t/=10)
    x[++x[0]]=t%10;

}

int main()
{
    int n;
    cin>>n;
    long long long p = 1;
    for(int i=3;i<=n-1;i++)
    	    p*=i;
        	cout<<p;
    return 0;
}
