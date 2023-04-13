#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex()
    {
       // cout<<"\n i am constructor0\n";
        real=img=0;
    }

    Complex( int n)
    {
       // cout<<"\n i am construct0r1\n";
        real=img=n;
    }


    Complex(int n , int m)
    {
       // cout<<"\n i am constructor2\n";
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
       // cout<<"\n copy constructor \n";
        real=comp.real;
        img=comp.img;

    }



    ~Complex()
    {
        //cout<<"\n i am destructor\n";

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

void print1(Complex c)
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

template <class T>
class Stack
{
int Size;
T *stk;
int tos ;

public:
    Stack()
    {   Size=5;
        tos = 0;
        stk=new T[Size];
   // cout<<"\ni am contractor\n";
    }

    Stack(int n)
    {   Size=n;
        tos=0;
        stk=new T [Size];
      //  cout<<"\nI am constructor_1\n";
    }
Stack(Stack &st)
{
   // cout<<"\n i am copy constructor.....\n";
    Size=st.Size;
    tos=st.tos;
    stk=new T[Size];
    for(int i=0;i<tos;i++)
        stk[i]=st.stk[i];
}

Stack operator =(Stack S1)
{ this->tos=S1.tos;
  this->Size=S1.Size;
  delete(this->stk);

  stk=new T[Size];
  for(int i=0;i<Size;i++)
  {
      this->stk[i]=S1.stk[i];
  }

}
Stack operator + (Stack s1)
{  Stack sres;
    sres.Size = this->Size+s1.Size;
    sres.tos = this->tos+s1.tos ;

    stk=new T [sres.Size];
    for(int i=0;i<this->Size;i++)
  {
      sres.stk[i]=this->stk[i];
  }
  for(int i=this->Size+1;i<sres.Size;i++)
  {
      sres.stk[i]=s1.stk[i];

  }
        return sres;


    }


int& operator [] (int i)
{
   return this->stk[i];

}

int IsFull()
{
    if (tos==Size)
        return 1;
    else
        return 0;
}


int IsEmpty()
{
    return tos==0;
}
void push(T n)
{
    if(tos==Size)
        cout<<"\nSTACK IS FULL\n";
    else
        stk[tos++]=n;
}
T pop()
{
    if(! IsEmpty())
        return stk[--tos];

}
int peak()
{
   return stk[tos-1];
}
Stack Reverse()
{   cout<<"\n reversing.........\n";

    int i;
    Stack reversed(this->Size);
    for(i=0;i<tos;i++)

    { reversed.stk[i]=stk[tos-1-i];

    }
    reversed.tos=tos;
    return reversed;
}

void PrintStack()
{
  int i;
    for(i=0;i<5;i++)

    { cout<<stk[i]<<"\n";}
}


~Stack()
{  for(int i=0;i<tos;i++)
    stk[i]=-1;
   // cout<<"\ni am Destractor\n";
    delete[]stk;
}


} ;

int main()
{
   Stack<int> S;
    S.push(10);
    S.push(20);
    cout<< S.pop()<<endl;

    Stack<char> S2(3);
    S2.push('A');
    S2.push('B');
    S2.push('C');
    cout<< S2.pop()<<endl;

    Stack<Complex> S3(4);
    Complex C1(2),C2(2);
    S3.push(C1);
    S3.push(C2);
    Complex C = S3.pop();
    print1(C);
    return 0;
}
