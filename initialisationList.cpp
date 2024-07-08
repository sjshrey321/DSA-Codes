#include<iostream>
using namespace std;
class student
{
    public:
    int age;
    int const roll;
    student(int r): roll(r)
    {}

    /*this means instead of doing intialising first and then changing the value giving us an error
    we are initialising it with a value r itself */
    // initialising list can be used for reference variable ( int &x;)
};
int main()
{
   // we can't declare the int const; like we can in int a; because int const can't accept an garbage value 
 // so does declaring int &p; will give error because it can't also accept garbage value 
    const int a=5; /* same as */ int const a=5;
    int const a=1;


}