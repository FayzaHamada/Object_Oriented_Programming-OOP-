#include <iostream>

using namespace std;
class Geoshape
{ protected:
    int dim1;
    int dim2;
public:
    Geoshape()
    {
        dim1=dim2=0;
    }
    Geoshape(int n)
    {
        dim1=dim2=n;
    }
    Geoshape(int n ,int m)
    {
        dim1=n;
        dim2=m;
    }
    int getDim1(){return dim1;}
    void setDim1(int D){dim1= D;}

    int getDim2(){return dim2;}
    void setDim2(int D){dim2= D;}

    float calcArea(){return 0;}
};

class RECT : public Geoshape
{ public:
    RECT(){ }
    RECT(int n1,int n2):Geoshape(n1,n2)
    { }
    float calcArea()
    {
    return Geoshape::getDim1() * Geoshape::getDim2();
    }
};

class Squar : protected Geoshape
{ public:
    Squar(){ }
    Squar(int n2):Geoshape(n2)
    { }
    void setDim(int D){ dim1=dim2= D;}
    float calcArea()
    {
    return Geoshape::getDim1()* Geoshape::getDim2();
    }
};

class Triangle : public Geoshape
{ public:
    Triangle(){ }
    Triangle(int n2,int n1):Geoshape(n2, n1)
    { }
    float calcArea()
    {
    return 0.5 * Geoshape::getDim1()* Geoshape::getDim2();
    }
};

class Circular : public Geoshape
{ public:
    Circular(){ }
    Circular(int n2):Geoshape(n2)
    { }
    float calcArea()
    {
    return 3.14* Geoshape::getDim1()* Geoshape::getDim2();
    }
};


int main()
{
    RECT R(3,4);
    cout<<"\n Rectangle Area = "<<R.calcArea();

    Squar v(3);
    cout<<"\n Square Area = "<<v.calcArea();

    v.setDim(4);
    cout<<"\n Square Area = "<<v.calcArea();


    Triangle z(3,4);
    cout<<"\n Rectangle Area = "<<z.calcArea();


    Circular d(3);
    cout<<"\n Circular Area = "<<d.calcArea();
    return 0;
}
