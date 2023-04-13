#include <iostream>

using namespace std;
#define MAX_SIZE 7



class  Circular_Queue
{   int Data=0;
    int arr[MAX_SIZE];
    int head, tail,Size;
public:


    Circular_Queue()
    {   Size=0;
        head= 0;
        tail=-1;
    cout<<"\ni am contractor\n";
    }

void Enqueue(int Data)
{
if(tail==MAX_SIZE-1)
{
    tail=0;
}
else
    tail++;


arr[tail]=Data;
cout<<Data<<endl;
Size++;
}

void Dequeue(int *pdata)
{*pdata=arr[head];
cout<<*pdata<<endl;
head=(head+1)%MAX_SIZE;
Size--;

}
int ISFULL()
{
     if(Size==MAX_SIZE)
    {
       return 1;
    }
    else return 0;
}

int ISEmpty()
{return !Size;
}

~Circular_Queue()
{
cout<<"\ni am contractor\n";
}





};

int main()
{
 int num;
    Circular_Queue que;
cout<<"the Queue before any DeQueue\n";

    que.Enqueue(10);
    que.Enqueue(20);
    que.Enqueue(30);
    que.Enqueue(40);
    que.Enqueue(50);
    cout<<"DeQueue data\n";

    que.Dequeue(&num);
    que.Dequeue(&num);
    que.Dequeue(&num);
    //que.Dequeue(&num);
    //que.Dequeue(&num);




    return 0;
}
