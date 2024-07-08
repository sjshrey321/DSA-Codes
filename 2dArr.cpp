#include<iostream>
using namespace std;
void transpose(int **arr,int n)
{
   for (int i=0;i<n;i++)
   {
    for (int j=0;j<n;j++)
    {
        if(i<j)
        {
            swap(arr[i][j],arr[j][i]);
        }
        //cout<<arr[i][j]<<endl;
    }
   } 
}
int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int *ptr[n];
    for (int i=0;i<n;i++)
    {
        ptr[i]=*(arr+i);
    }
    transpose(ptr,n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
}