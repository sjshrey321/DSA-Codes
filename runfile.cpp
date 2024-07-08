#include<iostream>
#include"stacks.cpp"
using namespace std;
int main()
{
    // int arr[][4]={{1,2,3,1},{4,5,6,2},{7,8,9,3}};
    // int *p[3];
    // for (int t=0;t<3;t++)
    // {
    //     p[t]=arr[t];
    // }
    stack s(5);
    s.push(1);
    s.push(4);
    s.push(3);s.push(1);s.push(7);s.push(10);
    s.top();
    cout<<s.size()<<endl;    



}