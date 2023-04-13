#include <iostream>

using namespace std;

class Stack
{
int Size;
int *stk;
int tos ;

public:
    static int counter;
    Stack()
    {   Size=5;
        tos = 0;
        stk=new int[Size];
   // cout<<"\ni am contractor\n";
    counter ++;
    }

    Stack(int n)
    {   Size=n;
        tos=0;
        stk=new int[Size];
       // cout<<"\nI am constructor_1\n";
        counter ++;
    }
Stack(Stack &st)
{
  //  cout<<"\n i am copy constructor.....\n";
    Size=st.Size;
    tos=st.tos;
    stk=new int [Size];
    for(int i=0;i<tos;i++)
        stk[i]=st.stk[i];
        counter++;
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
   // cout<<"\ni am Destractor\n";
    delete[]stk;
    counter--;
}

friend void viewcontent(Stack s);

} ;

int Stack ::counter =0;

void viewcontent (Stack s)
{
    cout<<"\n stack content is :\n";
    for(int i=0;i<s.tos;i++)
        cout<<s.stk[i]<<endl ;
}
int main()
{
   ///************* Copy Ctor Case(1): Pass by value to function ********************

    Stack S1;
    Stack S2;
    //Stack S3;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    viewcontent(S1);


    cout<<"\n*******************************************************************************************************\n";
  cout<<"\n number of objects is "<<Stack::counter;
    return 0;
}
