#include <iostream>

using namespace std;

void Swap(int *x, int *y) ///call by address
{
    int temp;
    temp = *x;
    *x =*y;
    *y = temp;
}
int main()
{
   int a=3;
   int b=4;
   cout<<"\nbefore swap"<<" A= "<<a<<" ,B= "<<b;
   Swap(&a,&b) ;//call by address
    cout<<"\nafter swap"<<" A= "<<a<<" ,B= "<<b;
    return 0;
}
