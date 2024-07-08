#include<iostream>
using namespace std;
void rev(int arr[],int n)
{
    for (int i=0;i<n/2;i++)
    {
        swap(arr[i],arr[n-i-1]);
    }
    
}
int main()
{
    int arr[3]={1,3,4};
    rev(arr,3);
    for (int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
}