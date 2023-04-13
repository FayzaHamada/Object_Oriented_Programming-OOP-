#include <iostream>

using namespace std;

class Stack
{
int Size;
int stk[5];
//int stk1[5];
int tos1;
int tos ;
//int Size;
public:
    Stack()
    {   //Size=0;
        tos=0;
    cout<<"\ni am contractor\n";
    }

    Stack(int n)
    {   Size=n;
        tos=0;
        cout<<"\nI am constructor_1\n";
    }

int IsFull()
{
    if (tos==5)
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
    if(IsFull()==0)
        stk[tos++]=n;
    else
        cout<<"Stack is full";
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


~Stack()
{
    cout<<"\ni am Destractor\n";
}



} ;

int main()
{
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<s1.peak();
    cout<<"\n";
    cout<<s1.peak();
    cout<<"\n";
    cout<<s1.pop();
    cout<<"\n";
   cout<<s1.pop();
    cout<<"\n";


 Stack s2(5);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    s2.push(6);
    s2.push(5);
    s2.push(6);
cout<<s2.Reverse().pop();
    //s2.PrintStack();


    return 0;
}
