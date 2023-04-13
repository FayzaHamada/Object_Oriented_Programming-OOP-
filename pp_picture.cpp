#include <iostream>
#include <graphics.h>

using namespace std;

class shape
{ protected:
    int shapecolor;
public:
    shape()
    {
        shapecolor=15; ///white
    }

    shape(int c)
    {
        shapecolor=c; ///white
    }

    void setshapecolor(int c)
    {
        shapecolor= c;
    }

    virtual void drawn() = 0 ;

};


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
        cout<<"\nI am constructor\n";
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
class Line: public shape
{
    point start; ///have x and y;
    point End ; ///Have x, y ;
public:
    Line(int x1,int y1,int x2,int y2,int C):start(x1,y1),End(x2,y2),shape(C)  ///constructor
    {

    }
   void drawn()
   {
       setcolor(shapecolor);
       line(start.getx(),start.gety(),End.getx(),End.gety());///built_in function draw line

   }
};

class Rect :public shape
{
    point UL; ///have x and y;
    point LR; ///Have x, y ;
public:
    Rect(int x1,int y1,int x2,int y2,int c):UL(x1,y1),LR(x2,y2),shape(c) ///constructor
    {

    }
   void drawn()
   {
       setcolor(shapecolor);
       rectangle(UL.getx(),UL.gety(),LR.getx(),LR.gety());///built_in function draw rectangle

   }
};

class Circle:public shape
{
    point center; ///have x and y;
    int rad; ///Have x, y ;
public:
    Circle(int x,int y,int r,int c):center(x,y),shape(c) ///constructor
    {
     rad =r;
    }
   void drawn()
   {
       setcolor(shapecolor);
       circle(center.getx(),center.gety(),rad);///built_in function draw circle

   }
};

class picture
{
    shape** pshapes;

    int shNum ;
public:
    picture()  //Parameterless constructor
    {
       shNum =0;
       pshapes =NULL;
    }

    picture(shape** psh ,int sn )
    {
       shNum=sn;
       pshapes=psh;
    }

    void paint()
    {
        int i;
        for(i=0;i<shNum;i++)
        {
            pshapes[i]->drawn();
        }
    }

};


int main()
{
    initwindow(700,500);

    Line L(10,20,200,300,14);
    Rect R(300,50,50,200,15);

    Circle C (300,50,30,14);

    shape* sharr[3];
    sharr[0]=&L;
    sharr[1]=&R;
    sharr[2]=&C;

   picture mypic(sharr,3);
   mypic.paint();
    getch();
    closegraph();
    return 0;
}
