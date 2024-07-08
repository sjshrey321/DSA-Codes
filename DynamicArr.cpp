#include<iostream>
using namespace std;
class DynamicArr
{
    // mainly dynamic arr means changing the size in fixed pattern like 5 10 20 40 ,,,, so to inc capacity// 
    int *data; //array 
    int ni; // next index 
    int capacity; // total size 
    public:
    DynamicArr() //parameterless constructor 
    {
        capacity=5;
        ni=0;
        data= new int[capacity];
        
        
    }
    DynamicArr(DynamicArr const &d) //copy constructor 
    {
        data=d.data;
        ni=d.ni;
        capacity=d.capacity;
    }
    void add(int a) //add function with only value to be inserted in the next index.
    {
        if (ni<capacity)
        {
            data[ni]=a;
        }
        else if (ni==capacity)
        {
            int *newdata= new int[2*capacity];
            for (int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            capacity*=2;
            delete []data;
            data=newdata;
            data[ni]=a;

        }
        ni++;
    }
    int get(int i) //get function to get the particular data at some defined index in array.
    {
        if (i<capacity and i>0)
        {
            return data[i];
        }
        else { return -1;}

    }
    void add(int a,int i) //function to add a function at particular defined index.
    {
         
    }
    void print() // print function for the array.
    {
        for (int i=0;i<ni;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};
