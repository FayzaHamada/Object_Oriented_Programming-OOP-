#include <iostream>

using namespace std;

class Base
{
    protected:
    int y;
    int x;
    public:
    Base ( )
    {
        x=2;
        y=3;
     cout<<"\ni am parameterless base ctor\n" ;

    }

     Base (int _X)
    {
        x=y= _x;
     cout<<"\ni am one parameter base ctor\n" ;

    }


    ~Base ()
    {
        cout<<"\ni am base destructor\n" ;
    }

   int getx(){return x;}
    void setx(int D){x= D;}

    int gety(){return y;}
    void sety(int D){y= D;}
  int Sum()
    { return x+y;}

    void show ()
    {
        cout<<"\n i am base function...x= "<<x<<"Y= "<<y;
    }
};


class driven :public Base
{  protected:
    int z;
    public:
    int getz(){return z;}
    void setz(int D){z= D;}

    driven( )
    { z=0;
    cout<<"\n i am derived parameterless ctor\n";
    }

    driven (int _L):Base( _L )
    {
        z= _L;
        cout<<"\n i am derived one parameter ctor\n";

    }

    driven (int N1 , int N2):Base( N1)
    {
        z= N2;
        cout<<"\n i am derived two parameters ctor\n";

    }

    int Sum()
    { return x+y+z;}

    void show ()
    {
        cout<<"\n i am derived function.....X= "<<x<<"y= "<<y<<"z= "<<z;
    }

};

class driven_2 :public driven
{
    int p;
    public:
    int getp(){return p;}
    void setp(int D){p= D;}

    driven_2 ()
    {
        p=0;
        cout<<"\n i am derived_2 parameterless ctor\n"
    }

    driven_2(int N1 , int N2 ,int N3 ):driven(N1, N2)
    {
        p=N3;
         cout<<"\n i am derived_2  3 parameter ctor\n"
     };

    int Sum()
    { return x+y+z+p;}

     void show ()
    {
        cout<<"\n i am derived_2 function.....X= "<<x<<"y= "<<y<<"z= "<<z<<"p= "<<p;
    }


};
int main()
{
    Base b1;
    driven d1(3);
    Base *Bptr1=&b1;
    Base *Bptr2=&d1;

    cout<<"\nsum with base\n"<<Bptr1->Sum();
    cout<<"\nsum with driven\n"<<Bptr2->Sum();
    return 0;
}
