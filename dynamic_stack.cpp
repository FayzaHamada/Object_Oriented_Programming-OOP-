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
        stk=new int[Size];
    cout<<"\ni am contractor\n";
    }

    Stack(int n)
    {   Size=n;
        tos=0;
        stk=new int[Size];
        cout<<"\nI am constructor_1\n";
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
{   int i;
    Stack reversed(5);
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


};
int main()
{
   ///************* Copy Ctor Case(1): Pass by value to function ********************

    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    S1.PrintStack();

   // cout<<"Num = "<<S1.pop()<<endl;
    //cout<<"Num = "<<S1.pop()<<endl;


    return 0;
}
