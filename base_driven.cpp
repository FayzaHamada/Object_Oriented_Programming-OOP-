#include <iostream>

using namespace std;

class Base
{
    protected:
    int y;
    int x;
    public:
    Base ()
    {
        x=0;
        y=0;
        cout<<"\ni am constructor\n" ;

    }

    ~Base ()
    {
        cout<<"\ni am destructor\n" ;
    }

   int getx(){return x;}
    void setx(int D){x= D;}

    int gety(){return y;}
    void sety(int D){y= D;}
    int Sum()
    { return x+y;}
};


class driven :public Base
{
    int z;
    public:
    int getz(){return z;}
    void setz(int D){z= D;}
    driven(){ };
    int Sum()
    { return x+y+z;}

};
int main()
{
    Base b1;
    b1.setx(5);
    b1.Sum();
    driven d1;
    int c1,c2;
    d1.setz(3);
   c1=b1.Sum();
   c2=d1.Sum();
    cout<<c1 <<endl;
    cout<< c2<<endl;
    return 0;
}
