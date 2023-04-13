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
int sum(int a=0,int b=1,int c=2)
{
   int result;
   result=a+b+c;
   return result;
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
}
int sum(int a=0,int b=1,int c=2)
{
   int result;
   result=a+b+c;
   return result;
}

int main()
{
//Complex c1(3,4),c2(5),c3;
//c3=c1.Add(c2);
    //return 0;
int s,s1,s2;
s=sum();
cout<<s<<endl;

s1=sum(1,4);
cout<<s1<<endl;
s2=sum(3,4,2);
cout<<s2;
return 0;
}
