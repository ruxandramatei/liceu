#include <iostream>

using namespace std;

class Complex{
  public:float re;
         float im;
         Complex();
         void set(float , float);
         void Afisare();
         void Adunare(Complex , Complex);
         friend Complex operator +(Complex, Complex);
         friend istream &operator >>(istream &, Complex& );
         friend ostream &operator <<(ostream &, Complex&);
};

istream &operator>>( istream  &input, Complex &a ) {
        input >> a.re >> a.im;
        return input;
     }
ostream &operator<<(ostream &output, Complex &a){
        if(a.im>0)
          output<<a.re<<"+"<<a.im<<"i\n";
        else if(a.im == 0)
          output<<a.re<<'\n';
        else
          output<<a.re<<a.im<<"i\n";
        return output;
}

Complex::Complex(){
  ;
}

void Complex::set(float a, float b){
  re = a;
  im = b;
}

void Complex::Afisare(){
  if(im>0)
    cout<<re<<" + "<<im<<"i\n";
  else if(im==0)
    cout<<re<<'\n';
  else
      cout<<re<<" "<<im<<"i\n";
}

void Complex::Adunare(Complex a, Complex b){
  re = a.re + b.re;
  im = a.im + b.im;
}

Complex operator+(Complex a, Complex b){
  Complex temp;
  temp.re = a.re + b.re;
  temp.im = a.im + b.im;

  return temp;
}


int main(){

  Complex c1 ;
  cin>>c1;
  // c1.set(12,4);
  // Complex c2;
  // c2.set(18,0);
  // Complex c3 ;
  // c3.set(0,0);
  // Complex c4;
  // c4.set(0,0);
  // c1.Afisare();
  // c2.Afisare();
  // c3.Adunare(c1,c2);
  // c3.Afisare();
  // c4 = c1 + c2;
  cout<<c1;
  return 0;
}
