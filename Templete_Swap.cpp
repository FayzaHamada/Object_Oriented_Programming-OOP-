#include <iostream>

using namespace std;

class Stack
{
int Size;
int *stk;
int tos ;

public:
    Stack()
    {   Size=5;
        tos = 0;
        stk=new int[Size];
    cout<<"\ni am contractor\n";
    }

    Stack(int n)
    {   Size=n;
        tos=0;
        stk=new int[Size];
        cout<<"\nI am constructor_1\n";
    }
Stack(Stack &st)
{
    cout<<"\n i am copy constructor.....\n";
    Size=st.Size;
    tos=st.tos;
    stk=new int [Size];
    for(int i=0;i<tos;i++)
        stk[i]=st.stk[i];
}

Stack operator =(Stack S1)
{ this->tos=S1.tos;
  this->Size=S1.Size;
  delete(this->stk);

  stk=new int [Size];
  for(int i=0;i<Size;i++)
  {
      this->stk[i]=S1.stk[i];
  }

}
Stack operator + (Stack s1)
{  Stack sres;
    sres.Size = this->Size+s1.Size;
    sres.tos = this->tos+s1.tos ;

    stk=new int [sres.Size];
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
void push(int n)
{
    if(tos==Size)
        cout<<"\nSTACK IS FULL\n";
    else
        stk[tos++]=n;
}
int pop()
{
    if(! IsEmpty() )
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
    cout<<"\ni am Destractor\n";
    delete[]stk;
}

friend void viewcontent(Stack s);

} ;
void viewcontent (Stack s)
{
    cout<<"\n stack content is :\n";
    for(int i=0;i<s.tos;i++)
        cout<<s.stk[i]<<endl ;
}


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


template<class T>
void Swap(T &x, T &y)
{
    T temp;
    temp = x;
    x =y;
    y = temp;
}
int main()
{
   ///************* Copy Ctor Case(1): Pass by value to function ********************

    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    viewcontent(S1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"*******************************************************************************************************";

    S4.pop();


    for(int i=0; i<10; i++)
        S4.push(-1);
    cout<<"Num = "<<S4.pop()<<endl;
    cout<<"Num = "<<S3.pop()<<endl;
    cout<<"Num = "<<S3.pop()<<endl;
    cout<<"\n************************************************************************************************\n";
    int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;
Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);

    cout<<"\nComplex1 After Swap: "<<endl;
    C1.Print1();
    cout<<"\nComplex2 After Swap: "<<endl;
    C2.Print1();

    return 0;

    }
