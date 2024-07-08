#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<string> v;
    v.push_back("hello");
    cout<<v[0]<<endl;
    sort(v[0].begin(),v[0].end());
    cout<<v[0]<<endl;
    string s;
    getline(cin,s); // normally we would right as cin.getline(name,size,delimmiter) // string in itself is mutable 
    // unlike python where we could not change any specific index of the string but here we can using indexes and 
    // treating it as if this is an array with unkown length.
    cout<<s.length();
    string b=s+"how you doing?"; //you can concatenate as well as in python 
    b.substr(1,5); //substring 
    int e=123;
    string e1=to_string(e);
    e= atoi(e1.c_str());
    cout<<e;
    e1.push_back("55".c_str());
    e1.push_back('4');
}