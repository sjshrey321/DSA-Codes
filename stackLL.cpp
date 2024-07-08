#include<iostream>
using namespace std;
class node
{
    private:
    int data;
    node *next;
    public:
    node(int a)
    {
        data= a;
        next=NULL;
    }
    void dirn(node *next)
    {
        this->next=next;
    }

};
int main()
{
    node head(4);
    node one(3);
    head.dirn(&one);


}