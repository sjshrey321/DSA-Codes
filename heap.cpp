#include<iostream> 
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std; 

//class heap 
class heap{
    public:
    int arr[100];
    int size; 

    heap()
    {
        arr[0] =-1; 
        size=0 ; 
    }
    // insert function 

    void insert(int val)
    {
        size++; 
        int index= size; 
        arr[index] = val ; 
        while(index>1) 
        {
            int parent = index/2 ; 
            if(arr[parent] < arr[index] )
            {
                swap(arr[parent],arr[index]) ; 
                index= parent ; 
            }
            else return ; 
        }
        return ; 
    }
    // print function 
    void print()
    {
        for(int i = 1; i<=size; i++) 
        {
            cout<<arr[i]<< " " ; 

        }
        cout<<endl;  
    }
    // delete function will delete the root of the heap 
    void dlt()
    {
       // base case 
        if ( size==0) return ; 
        swap(arr[1],arr[size]); 
        arr[size] = NULL; 
        int index = 1;
        while(index< size )
        {
            int l = 2*index; 
            int r= l+1; 
            if(l< size and r<size){
                if(arr[index]>arr[l] and arr[index] > arr[r])
                {
                    return ; 
                }
                if(arr[l] > arr[r]) 
                {
                    swap(arr[index], arr[l]); 
                    index= l; 
                }
                else
                {
                    swap(arr[index] , arr[r] ) ; 
                    index= r ; 
                } 

            }
            else if ( l<size) 
            { 
                if( arr[l] > arr[index]) swap(arr[index], arr[l ] ) ; 

            }
            else if ( r<size) 
            { 
                if( arr[r] > arr[index]) swap(arr[index], arr[r] ) ; 
                
            }
            return; 
            
        }

    }
};

// heapify algorithm 
void heapify(int arr[], int n , int i)
{
    if(n ==0 ) return; 
    int maxi = i; 
    int l = 2*i ; 
    int r = 2*i + 1 ; 
    if ( l <= n and arr[l]> arr[maxi]) 
    { 
        maxi= l ; 
    }
    if ( r<=n and arr[r]> arr[maxi] ) maxi = r; 
    if (maxi!=i ) 
    {
        swap(arr[i],arr[maxi] ) ; 
        heapify(arr, n , maxi) ; 
    }
    return ; 
} 
// heap sort 
void heapsort(int arr[],int n) 
{ 
    // O(nlogn) 
    if ( n <=1 ) return ; 
    // bult heap 
    for(int i= n/2; i>0 ; i++) 
    {
        heapify(arr,n, i) ; 
    }

    // sort heap 
    while(n>1) 
    {
        swap(arr[1],arr[n]); 
        n--; 
        heapify(arr,n,1) ; 

    }
    return ;

}
// sorting K sorted array ; 
int main()
{
    int k = 3; 
    int arr[7] = {6,5,3,2,8,10,9};
    priority_queue<int,vector<int>, greater<int> >  minH;
    int start= 0 ; 

    for(int i = 0 ; i<7; i++)
    { 
        minH.push(arr[i]);
        if(minH.size()>k)
        {
            arr[start]= minH.top();            
            minH.pop();
            start++;
        }

    }
    while(!minH.empty())
    {
        arr[start]=minH.top();
        minH.pop();
        start++; 
    }
    for(int i = 0 ; i<7; i++)
    {
        cout<<arr[i]<<" "; 

    }

    return 0 ;
}