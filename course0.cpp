#include<iostream>
using namespace std;
int max(int arr[],int size)
{
    if (size==1)
    {
        cout<<arr[0];
    }
    else
    {
       int max1=max(arr,size/2-1);
       int max2=max(arr +size/2,size/2-1);
    }
}
int main()
{}
