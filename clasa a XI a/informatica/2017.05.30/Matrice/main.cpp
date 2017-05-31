#include <iostream>

using namespace std;

class Matrice{

    public: int a[20][20],n;
            void citire();
            void afisare();
            int suma();
            int maxim();
            int minim();
            void ord();
            bool simetric();
            long long produs();
            friend istream& operator >>(istream& , Matrice& );
            friend ostream& operator <<(ostream& , Matrice& );
            friend Matrice operator +(Matrice , Matrice );

};

long long Matrice::produs(){
  long long p = 1;
  for(int i=1;i<=n;i++)
    p*=a[1][i]*a[i][1]*a[n][i]*a[i][n];
  return p;
}

bool Matrice::simetric(){
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      if(a[i][j]!=a[j][i])
        return false;
  return true;
}

void Matrice::ord(){
  int v[101];
  for(int i=1;i<=n;i++)
    v[i]=a[i][i];
  for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
      if(v[i]>v[j]){
        int temp = v[i];
        v[i]=v[j];
        v[j]=temp;
      }
      for(int i=1;i<=n;i++)
        a[i][i]=v[i];
}

int Matrice::suma(){
    int s = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            s+=a[i][j];
        }
    return s;
}

int Matrice::maxim(){
    int t1 = 1,t2=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(a[t1][t2]<a[i][j]){
              t1=i;
              t2=j;
            }
        }
    return a[t1][t2];
}

int Matrice::minim(){
    int t1 = 1,t2=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(a[t1][t2]>a[i][j]){
              t1=i;
              t2=j;
            }
        }
    return a[t1][t2];
}

void Matrice::citire(){

    cout<<"n = ";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cout<<"a [ "<<i<<" ] [ "<<j<<" ] = ";
            cin>>a[i][j];
        }
}

void Matrice::afisare(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    cout<<"\n";
}

istream& operator >>(istream& input, Matrice& a){

    cout<<"n = ";
    input>>a.n;
    for(int i=1;i<=a.n;i++)
        for(int j=1;j<=a.n;j++){
            cout<<"a [ "<<i<<" ] [ "<<j<<" ] = ";
            input>>a.a[i][j];
        }
}

ostream& operator <<(ostream& output, Matrice& a){

    for(int i=1;i<=a.n;i++){
        for(int j=1;j<=a.n;j++)
            output<<a.a[i][j];
        output<<'\n';
    }

}

Matrice operator +(Matrice b, Matrice& a){

    Matrice c;

    if(a.n==b.n){
      c.n = a.n;
      for(int i=1;i<=a.n;i++){
          for(int j=1;j<=a.n;j++)
              c.a[i][j]=a.a[i][j]+b.a[i][j];
      }
      return c;
  }
}

int main()
{
    Matrice a;
    cin>>a;
    cout<<a.produs();
    return 0;
}
