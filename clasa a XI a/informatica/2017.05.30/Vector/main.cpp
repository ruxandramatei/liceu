#include <iostream>

using namespace std;

class Vector{
    public:
        Vector();//ok
        Vector(int );//ok
        Vector(int , int );//ok
        int v[100], n;//ok
        void citire();//ok
        void afisare();//ok
        int suma();//ok
        void ordonare();//ok
        int maxim();//ok
        int minim();
        void adaugare(int );//ok
        void sumaV(Vector, Vector);//ok
        int prodImp();
        void quick(int , int );
        bool multime();
        friend istream& operator >> (istream& , Vector&);
        friend ostream& operator << (ostream& , Vector&);
        friend Vector operator +(Vector , Vector);
        friend Vector operator +(Vector , int);
        friend int operator +(int , Vector);
        friend Vector operator -(Vector , Vector);
        friend Vector operator -(Vector , int);
        friend int operator -(int , Vector);

};

bool Vector::multime(){
  cout<<"Naspa"
  for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
      if(v[i]==v[j])
        return false;
  return true;
  cout<<"Wat-seo!";
}

istream& operator >>(istream& input, Vector& a){

    input>>a.n;
    for(int i=1;i<=a.n;i++)
        input>>a.v[i];

}

ostream& operator <<(ostream& output, Vector& a){

    for(int i=1;i<=a.n;i++)
        output << a.v[i]<<" ";
    output<<'\n';

}
Vector operator -(Vector a, Vector b){

    if(a.n !=b.n)
        return NULL;
    else{
        Vector c;
        c.n = a.n;
        for(int i=1;i<=a.n;i++)
            c.v[i] = a.v[i]-b.v[i];
        return c;
    }

}

Vector operator -(Vector a, int b){

        Vector c;
        c.n = a.n;
        for(int i=1;i<=a.n;i++)
            c.v[i] = a.v[i]-b;
        return c;
}

int operator -(int b, Vector a){

        for(int i=1;i<=a.n;i++)
            b -= a.v[i];
        return b;
}

Vector operator +(Vector a, Vector b){

    if(a.n !=b.n)
        return NULL;
    else{
        Vector c;
        c.n = a.n;
        for(int i=1;i<=a.n;i++)
            c.v[i] = a.v[i]+b.v[i];
        return c;
    }

}

Vector operator +(Vector a, int b){

        Vector c;
        c.n = a.n;
        for(int i=1;i<=a.n;i++)
            c.v[i] = a.v[i]+b;
        return c;
}

int operator +(int b, Vector a){

        for(int i=1;i<=a.n;i++)
            b += a.v[i];
        return b;
}

Vector::Vector(){
    n = 0;
}

Vector::Vector(int x){

    n = x;
    for(int i=1;i<=n;i++)
        v[i]=0;

}

Vector::Vector(int m, int x){

    n = m;
    for(int i=1;i<=n;i++)
        v[i]=x;

}

void Vector::citire(){

    cout<<"n = ";
    cin>>n;
    cout<<"\nelemente : ";
    for(int i=1;i<=n;i++)
        cin>>v[i];

}

void Vector::afisare(){

    for(int i=1;i<=n;i++)
        cout<<v[i]<<' ';
    cout<<"\n";

}

int Vector::suma(){

    int s = 0;
    for(int i=1;i<=n;i++)
        s+=v[i];
    return s;

}

void Vector::ordonare(){
    for(int i=1;i<=n;i++)
        for(int j = i+1;j<=n;j++)
            if(v[i]>v[j])
                swap(v[i],v[j]);
}

int Vector::maxim(){

    int p = 1;
    for(int i=2;i<=n;i++)
        if(v[p]<v[i])
            p = i;
    return v[p];
}

int Vector::minim(){

    int p = 1;
    for(int i=2;i<=n;i++)
        if(v[p]>v[i])
            p = i;
    return v[p];
}

int Vector::prodImp(){
  int p = 1;
  for(int i=1;i<=n;i++)
    if(v[i]%2==1)
      p*=v[i];
  return p;
}

void Vector::quick(int inf, int sup){
  int st = inf, dr = sup, piv = v[(st+dr)/2];
  while(st<=dr){
    while(v[st]<piv && st<sup)
      st++;
    while(v[dr]>piv && dr>inf)
      dr++;
    if(st<=dr){
      int temp = v[st];
      v[st]=v[dr];
      v[dr]=temp;
    }
  }
  if(st<sup)quick(st,sup);
  if(dr>inf)quick(inf,dr);
}

void Vector::adaugare(int dead){
    n++;
    v[n]=dead;
}

void Vector::sumaV(Vector v1, Vector v2){

    if(v1.n == v2.n){
        for(int i=1;i<=v1.n;i++)
            v[i] = v1.v[i]+v2.v[i];
    }
    else
        cout<<"Lungimi diferite!";

}



int main()
{
    Vector a,b;
    cin>>a;
    cin>>b;
    cout<<a.multime();
    a.quick(1,a.n);
    cout<<a;
    cout<<a.multime();
    return 0;
}
