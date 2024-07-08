#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // no size requirement 
    // we can insert as many elements as we want 
    vector<int> v;// static allocation
    vector<int> *vp=new vector<int>();// dynamic allocation
    // to insert
    v.push_back(10);// it's like append in the list
    cout<<v[0]<<endl;  
    // if we add using v[5] while we have only push backed 3 items then that data will be lost 
    // so instead we can use at () function  it will show error for the value if we access any out of range value 
   // cout<<v.at(6);
    // push_back funtions lets you pop the last element this analogy add last and pop last is called stacking
    v.pop_back();
    //cout<<v.at(0);
    // size funcitons
    cout<<v.size()<<endl;
    //capacity of the functions (it is same as we did it in dynamic array)
    cout<<v.capacity()<<endl;
    // parameterisation initialisation of the function 
    vector<int> a(5,-1);
    cout<<a[2]<<endl;
    // sort function in vector 
    sort(a.begin(),a.end());


    
}