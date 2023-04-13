#include <iostream>

using namespace std;

#define MaxSize 7



class  Shift_Queue
{
    int arr[MaxSize];
    int head, tail;
public:


    Shift_Queue()
    {   //Size=0;
        head=tail=-1;
    cout<<"\ni am contractor\n";
    }


void Enqueue(int data)
{
    if(tail == MaxSize - 1)
    {
       return;
    }

    if(head == -  1)
        head++;

    tail++;
    arr[tail] = data;
}


void Shift(Shift_Queue q)
{   int index;
    for(index=0;index<tail;index++)
{
   arr[index]=arr[index+1];
}
tail--;
}


int Dequeue(Shift_Queue q,int data)
{
    if(head == -1 || head > tail)
        return 0;

    data = arr[head];

    Shift(q);

    return 1;}

    ~Shift_Queue()
    {
    cout<<"\ni am contractor\n";
    }

};

int main()
{   int num;
    Shift_Queue que;

    que.Enqueue(10);
    que.Enqueue(20);
    que.Enqueue(30);
    que.Enqueue(40);
    que.Enqueue(50);
    cout<<"the Queue before any DeQueue\n";

    while(que.Dequeue(que,num))
   {
       cout<<"\n" << num;
    }

    cout<<"the Queue After DeQueue\n";

    que.Enqueue(10);
    que.Enqueue(20);
    que.Enqueue(30);
    que.Enqueue(40);
    que.Enqueue(50);

    que.Dequeue(que,num);
    que.Dequeue(que,num);

    while(que.Dequeue(que,num))
    {
        cout<<"\n"<< num;
    }

    return 0;
}

