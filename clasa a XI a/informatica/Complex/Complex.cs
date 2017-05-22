using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Complex{

  class Complex{
    private int re;
    private int im;
    public Complex(){
      ;
    }
    public Complex(int i, int j){
      re = i;
      im = j;
      }
    public void Afisare(){
      Console.WriteLine("{0} + {1}i",re,im);
    }
    public static Complex operator -(Complex c)
     {
         Complex temp = new Complex();
         temp.im = -c.im;
         temp.re = -c.re;
         return temp;
     }
     public static Complex operator +(Complex c1,Complex c2){
        Complex temp = new Complex();
        temp.im = c1.im + c2.im;
        temp.re = c1.re + c2.re;
        return temp;
     }
     public static Complex operator *(Complex c1,Complex c2){
       Complex temp = new Complex();
       temp.re = c1.re*c2.re -c1.im*c2.im;
       temp.im = c1.im*c2.re +c1.re*c2.im;
       return temp;
     }
  }

  class Program{
    public static void Main(string[] args){
      Complex c1 = new Complex(10, 13);
      Console.Write("C1: ");
      c1.Afisare();
      Complex c2 = new Complex();
      Console.Write("C2: ");
      c2.Afisare();
      c2 = -c1;
      Console.Write("C2: ");
      c2.Afisare();
      Complex c3 = new Complex();
      Console.Write("C3: ");
      c3 = c1 + c2;
      c3.Afisare();
      Complex c4 = new Complex();
      Console.Write("C4: ");
      c4 = c1 * c2;
      c4.Afisare();
    }
  }
}
