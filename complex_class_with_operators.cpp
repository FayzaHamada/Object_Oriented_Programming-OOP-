#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex()
    {
        cout<<"\n i am constructor0\n";
        real=img=0;
    }

    Complex( int n)
    {
        cout<<"\n i am construct0r1\n";
        real=img=n;
    }


    Complex(int n , int m)
    {
        cout<<"\n i am constructor2\n";
        real=n;
        img=m;
    }

    Complex operator -(Complex &c)
    {
        Complex cres(this->real-c.real,this->img-c.img);
        return cres;

    }

    Complex operator -(int n)
    {
        Complex cres(n-this->real , this->img);
        return cres;
    }

Complex operator !=(Complex c)
{ if (this->real!=c.real && this->img !=c.img)
  cout<<"\n not equal\n";
  else
    cout<<"\n not equal\n";
}

Complex operator >(Complex c)
{ if (this->real>c.real && this->img >c.img)
  cout<<"\n greater than>\n";
  else
    cout<<"\n lower than\n";
}

Complex operator >=(Complex c)
{ if (this->real>=c.real && this->img >=c.img)
  cout<<"\n greater than or equal\n";
  else
    cout<<"\n not >= \n";
}

Complex operator <=(Complex c)
{ if (this->real<=c.real && this->img <=c.img)
  cout<<"\n lower than or equal\n";
  else
    cout<<"\n not <= \n";
}
 Complex operator <(Complex c)
{ if (this->real<c.real && this->img <c.img)
  cout<<"\n lower than <\n";
  else
    cout<<"\n greater than\n";
}


Complex operator ==(Complex c)
{ if (this->real==c.real && this->img ==c.img)
  cout<<"\n equal\n";
  else
    cout<<"\n not equal\n";
}

Complex operator --(int)
{
   Complex temp(*this);
   this->real--;
   return temp;
}

Complex operator --()
{
   this->real--;
   return *this;
}

Complex operator -=(Complex c)
{
    Complex cres (this->real-c.real,this->img-c.img);
    return cres;
}

    operator int()
{
    return (this->real + this->img);
}

Complex operator [] (char r)
{ Complex cres;
 if(r=='R')
    cres=(this->real);
 else
    cres=(this->img);
    return cres;



}

    Complex Add(Complex c2);
    void SetReal(int R);

    void SetImg(int I)
    { img=I; }

    int GetReal()
    { return real; }

    int GetImg()
    { return img; }

    Complex (Complex &comp)
    {
        cout<<"\n copy constructor \n";
        real=comp.real;
        img=comp.img;

    }



    ~Complex()
    {
        cout<<"\n i am destructor\n";

    }


};

void Complex::SetReal(int R)
    { real=R; }


Complex Complex::Add(Complex c2)
{ Complex c3;
    c3.SetReal( this->real +c2.GetReal());
    c3.SetImg( this->img+c2.GetImg());
    return c3;
    }

Complex Subtract(Complex c1,Complex c2)
{ Complex c3;
    c3.SetReal( c1.GetReal()-c2.GetReal());
    c3.SetImg( c1.GetImg()-c2.GetImg());
    return c3;
    }

void print(Complex c)
{ if(c.GetReal()==0 && c.GetImg()!=0 )
 {
     cout<<"your complex number c1= " << c.GetImg()<<"i"<<"\n";
 }
 else if(c.GetImg()==0)
 {
     cout<<"your complex number c1 = " << c.GetReal()<<"\n";
 }

 else if(c.GetImg()==0 && c.GetReal()==0)
 {
 cout<<"your complex number c1 = " <<0<<"\n";

 }

else
  {cout<<"your complex number c1 = " << c.GetReal();
    {
    if(c.GetImg()>0)
      cout<<"+"<<c.GetImg()<<"i"<<"\n";
    else
      cout<<c.GetImg()<<"i"<<"\n";}
}
};
 Complex operator -(int n,Complex c)
    {
        Complex cres(c.GetReal()-n , c.GetImg());
        return cres;
    }

int main()
{
Complex c1(3,4),c2(5),c3,c4;
//c3=c1.Add(c2);
c3=c1-c2;
print(c3);
c4=c1-7;
print(c4);
c4=7-c1;
print(c4);
c2!=c1;
print(c2);
c2=c1--;
print(c2);
c2=--c1;
print(c2);
c2==c1;
print(c2);
c1>c2;
print(c1);
c1>=c2;
print(c1);
c1<c2;
print(c1);
c1<=c2;
print(c1);
(int) c1;
print(c1);
print(c1['R']);
print(c1['I']);
    return 0;
}
