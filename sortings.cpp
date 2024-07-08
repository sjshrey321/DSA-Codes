
#include<iostream>
#include<algorithm> // for in-built sort funtion 
using namespace std;
void selectionSort(int *arr,int n)
{
    // left hand side min swap approach 
    // one loop and other for finding minimum 
    for(int i =0 ; i<n-1; i++)
    {
        int smallest = i+1;
        for(int j =i+2 ; j<n; j++)
        {
           if(arr[smallest]>arr[j]) smallest=j;

            

        }
        if (arr[smallest]<arr[i]) swap(arr[smallest],arr[i]);
    }

}
void BubbleSort()
{}
void QuickSort()
{}
void InsertionSort()
{}
void merging(int * a , int s , int e) 
{
    if(s==e) return ; 
    int *ans= new int[s-e+1] ; 
    int mid = (s+e)/2;
    int l=s; 
    int r= mid+1;
    int i = 0; 
    while (l<=mid and r<=e)
    {
        if(a[l]<a[r]){
            ans[i]=a[l]; 
            l++;
        }
        else{
            ans[i]=a[r]; 
            r++; 
        }
        i++; 
    }
    while(l<=mid)
    {
        ans[i]=a[l]; 
        l++; 
        i++; 
    }
    while(r<=e)
    {
        ans[i]=a[r];
        r++; 
        i++; 
    }
    a=ans; 
    delete []ans; 
    return; 

    


}
void mergeSort(int * arr, int s, int e ) 
{
    // base case 
    if ( s>=e) return; 
    int mid = (s+e)/2 ; 
    
    // sort left and right side 
    mergeSort(arr,s,mid); 
    mergeSort(arr,mid+1,e) ;
    merging(arr,s,e) ; 



}
int main()
{
    int a[3]={3,1,2};
    selectionSort(a,3);
    for (int i=0;i<3;i++)
    {
        cout<<a[i]<<" ";

    }
}