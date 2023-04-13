#include <iostream>
#include <graphics.h>

using namespace std;


class point
{
    int x;
    int y;
public:
    point()
    {
        x=y=0;
    }

    point(int l)
    {
        x=y=l;
    }
    point(int n ,int m)
    {
        x=n;
        y=m;
    }
    ~point()
    {
        cout<<"I am constructor";
    }
    void setx(int _X)
    {
        x=_X;
    }
    int getx( )
    {
        return x;
    }

     void sety(int _Y)
    {
        x=_Y;
    }
    int gety( )
    {
        return y;}

};

///composition relationship (one object form part inside the whole)
class Line
{
    point start; ///have x and y;
    point End ; ///Have x, y ;
public:
    Line(int x1,int y1,int x2,int y2):start(x1,y1),End(x2,y2)  ///constructor
    {

    }
   void drown()
   {
       setcolor(YELLOW);
       line(start.getx(),start.gety(),End.getx(),End.gety());///built_in function draw line

   }
};

class Rect
{
    point UL; ///have x and y;
    point LR; ///Have x, y ;
public:
    Rect(int x1,int y1,int x2,int y2):UL(x1,y1),LR(x2,y2) ///constructor
    {

    }
   void drown()
   {
       setcolor(BLUE);
       rectangle(UL.getx(),UL.gety(),LR.getx(),LR.gety());///built_in function draw rectangle

   }
};

class Circle
{
    point center; ///have x and y;
    int rad; ///Have x, y ;
public:
    Circle(int x,int y,int r):center(x,y) ///constructor
    {
     rad =r;
    }
   void drown()
   {
       setcolor(RED);
       circle(center.getx(),center.gety(),rad);///built_in function draw circle

   }
};
int main()
{

    initwindow(400,300);
    Line L(10,20,200,300);
    L.drown();

    Rect R(50,100,200,300);
    R.drown();

    Circle C(100,100,100);
    C.drown();

    getch();
    closegraph();
    return 0;
}
