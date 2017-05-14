#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pb.in");
ofstream out("pb.out");

int n, i, t, aux, v[100005];
int main()
{
    in >> n;
    v[0] = 1;//numarul de cifre
    v[1] = 1;
    n = n * (n-1) / 2;
    for( ; n; -- n)
    {
        t = 0;
        for(i = 1; i <= v[0]; i ++)
        {
            aux = v[i] * 3 + t;
            v[i] = aux % 10;
            t = aux / 10;
        }
        while(t)
        {
            v[ ++v[0] ] = t % 10;
            t = t / 10;
        }
    }
    for(i = v[0]; i; -- i)
        out << v[i];
    return 0;
}
