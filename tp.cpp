#include<iostream> 
#include<vector> 
#include"stacksInbuilt.cpp"
using namespace std; 
int main ()
{
    string a="abbccd"; 
    cout<<rmvdup(a);
}



/* 
well basically what this algo is that if the element we assume to be majority element 
in a array of numbers must be more or equal then the rest of the numbers .
assumption is that there is majority element in the array . 
*/
int MooreAlgo( int *a, int n)
{
    int maj= a[0]; 
    int count=1 ;
    for (int i=0; i<n; i++)
    {
        if (a[i]== maj)
        {
            count ++; 
        }
        else 
        {
            count --;
        }
    }
    if (count!=0)
    {
        return maj;
    }
    else {MooreAlgo(a,n);}
}
