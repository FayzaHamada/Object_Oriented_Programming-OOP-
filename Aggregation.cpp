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

class picture
{
    Circle* pcircles;
    Rect* prects;
    Line* plines ;
    int CNum;
    int RNum;
    int LNum ;
public:
    picture()  //Parameterless constructor
    {
        CNum=RNum=LNum=0;
        pcircles=NULL;
        prects=NULL;
        plines=NULL;
    }

    picture(Circle* pc,Rect* pr,Line*pl,int cn,int rn, int ln)
    {
       CNum=cn;
       RNum=rn;
       LNum=ln;
       pcircles=pc;
        prects=pr;
        plines=pl;
    }

    void setcircle(Circle* cptr,int cn)
    {
        pcircles=cptr;
        CNum=cn;
    }
void setrect(Rect* rptr,int rn)
    {
        prects=rptr;
        RNum=rn;
    }
void setline(Line* lptr,int ln)
    {
        plines=lptr;
        LNum=ln;
    }

    void paint()
    {
        int i;
        for(i=0;i<CNum;i++)
        {
            pcircles[i].drown();
        }
        for(i=0;i<RNum;i++)
        {
            prects[i].drown();
        }
        for(i=0;i<LNum;i++)
        {
            plines[i].drown();
        }





    }

};


int main()
{

    initwindow(400,300);
    Line Larr[1]={Line(10,20,200,300)};
   // L.drown();

    Rect Rarr[2]={Rect(30,40,170,100),Rect(300,50,50,200)};
   // R.drown();

    Circle Carr[3]={Circle(100,100,100),Circle(200,100,100),Circle(300,50,30)};
   // C.drown();

   picture mypic(Carr,Rarr,Larr,3,2,1);
   mypic.paint();
    getch();
    closegraph();
    return 0;
}
