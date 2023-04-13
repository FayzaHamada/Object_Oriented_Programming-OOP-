#include <iostream>
#include <graphics.h>
#include <windows.h>

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
class Line
{   bool Flage;
    point start; ///have x and y;
    point End ; ///Have x, y ;
public:
    Line(int x1,int y1,int x2,int y2,bool F):start(x1,y1),End(x2,y2)  ///constructor
    {
     Flage=F;
    }
   void drown()
   {   if(Flage)
      {
        setcolor(YELLOW);}
        else
        {
        setcolor(WHITE);}

       line(start.getx(),start.gety(),End.getx(),End.gety());///built_in function draw line


   }
};

class Rect
{   bool Flage;
    point UL; ///have x and y;
    point LR; ///Have x, y ;
public:
    Rect(int x1,int y1,int x2,int y2,bool F):UL(x1,y1),LR(x2,y2) ///constructor
    {
     Flage=F;
    }
   void drown()
   {   if(Flage)
      {
        setcolor(BLUE);}
        else
        {
        setcolor(WHITE);}

       rectangle(UL.getx(),UL.gety(),LR.getx(),LR.gety());///built_in function draw rectangle

   }
};

class Circle
{ bool Flage;

    point center; ///have x and y;
    int rad; ///Have x, y ;
public:
    Circle(int x,int y,int r,bool F):center(x,y) ///constructor
    {
     rad =r;
     Flage=F;
    }
   void drown()
   { if(Flage)
      {
        setcolor(RED);}
        else
        {
        setcolor(WHITE);}
       //Flage=!Flage;

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

    initwindow(819,460);
    Line Larr[9]={Line(525,183,525,325,true),Line(525,200,480,250,true),Line(525,200,594,255,true),Line(525,325,480,380,true),
    Line(525,325,615,380,true),Line(215,204,275,126,true),Line(400,204,345,126,true),Line(215,204,400,204,true),Line(400,204,480,250,true)};
   // L.drown();

    Rect Rarr[2]={Rect(225,287,396,322,true),Rect(288,204,331,286,true)};
   // R.drown();
    Circle Carr[3]={Circle(310,126,35,true),Circle(525,153,30,true),Circle(480,250,10,true)};
   // C.drown();

   picture mypic(Carr,Rarr,Larr,3,2,9);
   mypic.paint();
  // delay(1000);
   Line Larrary[9]={Line(525,183,525,325,true),Line(525,200,480,270,true),Line(525,200,594,255,true),Line(525,325,480,380,true),
    Line(525,325,615,380,true),Line(215,204,275,126,false),Line(400,204,345,126,false),Line(215,204,400,204,false),Line(400,204,480,270,true)};
   // L.drown();
   Circle Carray[3]={Circle(310,126,35,false),Circle(525,153,30,true),Circle(480,270,10,true)};

mypic.setcircle(Carray,3);
mypic.setline(Larrary,9);
delay(2000);
cleardevice();
//setcolor(WHITE);
   mypic.paint();
  // setcolor(WHITE);


    getch();
    closegraph();
    return 0;
}
