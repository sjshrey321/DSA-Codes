#include<iostream>
using namespace std;
class stack // using dynamic array 
{
    private:
    int *arr;
    int ni;
    public:
    stack()
    {
        arr= new int[4]; 
        ni=0;
    }
    stack(int const &n){
        arr= new int[n]; 
        ni=0;  
    }
    int size()
    {
        return ni;
    }
    void push(int n){
        
        if (ni<sizeof(arr))
        {
            arr[ni]=n;
            ni++;  
        }
        else
        {
           int *temp=new int[2*sizeof(arr)];
           for (int i=0;i<ni;i++)
           {
            temp[i]=arr[i];
           } 
           arr=temp;
           delete[] temp;

        }
    }
    void pop()
    {
        if (ni==0){cout<<"Stack is empty"<<endl;}
        else {ni--;}
    }
    bool isEmpty()
    {
        if(ni==0){return true;}
        else {return false;}
        
    }
    void top()
    {
        cout<<arr[ni-1]<<endl;
    }
};

// stacks using templates 
template<typename t>
class stacks
{
    private:
    t *arr;
    int ni;
    public:
    stack()
    {
       arr = new t[4];
       ni=  0;
    }
};
