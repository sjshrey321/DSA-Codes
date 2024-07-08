#include<iostream>
#include"gcd.cpp"
using namespace std;
class fraction
{
    private:
    int num;
    int denum;
    public:
    fraction(int num,int denum)
    {
        this->num=num;
        this->denum=denum;
    }
    void print()
    {
        cout<<num<<"/"<<denum<<endl;
    }
    void simplify()
    {
        int a=gcd(num,denum);
        this->num=num/a;
        this->denum=denum/a;
    }
    fraction operator+ (fraction const &f2) 
    {
        this->num=this->num*(f2.denum)+ (f2.num)*this->denum;
        this->denum=lcm(this->denum,f2.denum);
        simplify();
        fraction fn(num,denum);
        return fn;
    }
    void multiply(fraction const &f2) //these are binary operators
    {
        num*=f2.num;denum*=f2.denum;
    } 
};