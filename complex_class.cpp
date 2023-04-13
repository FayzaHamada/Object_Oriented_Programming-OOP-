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

    Complex Add(Complex c2);
    void SetReal(int R);

    void SetImg(int I)
    { img=I; }

    int GetReal()
    { return real; }

    int GetImg()
    { return img; }

};

void Complex::SetReal(int R)
    { real=R; }


Complex Complex::Add(Complex c2)
{ Complex c3;
    c3.SetReal( real +c2.GetReal());
    c3.SetImg( img+c2.GetImg());
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
}

int main()
{
Complex c1,c2,sum,sub;
c1.SetReal(0);
c1.SetImg(3);

c2.SetReal(1);
c2.SetImg(2);

sum=c1.Add(c2);
sub=Subtract(c1,c2);
print(c1);
print(c2);
print(sum);
print(sub);
cout<<"\nCase2******************************************************************************\n";
c1.SetReal(0);
c1.SetImg(0);
print(c1);



    return 0;
}
