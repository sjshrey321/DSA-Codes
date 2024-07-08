#include<iostream>
using namespace std;
// predefined classes which can be used for multiple datatypes // and need no to be 
// written again .
template<typename t> // template t can be any data type 
class Pair
{
    private:
    t x;
    t y;
    public:


};
/* so now while declaring and object of this class called Pair we'll need to
data type aswell so we'll write something like Pair<int> object_name */
 
// we can also add multiple templates like template<typename a,typenname b>
// it can also be like pair<int,pair<int,char>> something of this sort 
int main()
{
    Pair<Pair<int>> p;
    // like this pair within pair 
    // we might be able to create vector through this 

    
}