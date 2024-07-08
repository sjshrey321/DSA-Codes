#include<iostream>
using namespace std;
/* in static member the member is assigned a single elemental group of blocks required for the member 
and the memory remains the constant for all the object in the class*/

class student
{
    public:
    int a; // non static member hence defined different for object hence it's an object property
    static int totstd; // static member hence it is an class property.
    // static function
    static int gettotstd()
    {   
        return totstd;// static function can only return static members we can't use object variables  i.e 
        // non static member.
    
    }

};
int student::totstd=5; //initialisation of the static member.( initialisation has to be outside a function)
int main()
{
    // to access an static member 
    
    cout<<student::totstd; // :: is called scope resolution operator.

}