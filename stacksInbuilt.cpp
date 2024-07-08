#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std; 



// Balanced Paranthesis 

// 1; valid parenthesis 

/*  in this problem we will be given a string and the brackets must be proper the function will 
be a bool . */ 


bool brackets( string b)
{
    stack<char> s; 
    for (int i=0 ; i< b.size() ; i++  ) 
    {
        if ( b[i]== '('|| b[i]== '{' || b[i]== '[' )
        {
            s.push(b[i]);
        }
        else 
        {
            if (s.empty()) return false;
            else if ( b[i]== ')' ) 
            {
                if( s.top() == '(') s.pop(); 
                else return false ;
                if ( s.top() == '{') s.pop();
                else return false ; 
                if (s.top() == '[' ) s.pop(); 
                else return false ; 

            }

        }
    }
    if ( s.empty()) return true ;
}


// reverse polish notation question . 
// in this we write ((2+1)*3) = [2 1 + 3 * ]
// so in order to accomplish it we'll use stacks 

int revPolish( vector<string>& a)
{
    
    int ans;
    stack<int> operants; 
    for (int i=0 ; i< a.size() ; i++)
    {
        if(a[i]=="*" || a[i]=="+" || a[i]== "-" || a[i] == "/")
        {
            int* p1= new int(operants.top());
            operants.pop();
            int* p2 = new int(operants.top());
            operants.pop(); 
            if (a[i]=="*")
            {
                ans= (*p1)*(*p2);
            }
            if (a[i]=="+")
            {
                ans= *p1 + *p2;
            }
            if (a[i]=="-")
            {
                ans= *p1 - *p2;
            }
            if (a[i]=="/")
            {
                ans= *p1 / *p2;
            }
            operants.push(ans);
        }
        else 
        {
            operants.push(atoi(a[i].c_str()));
        }
    }
    return operants.top();
}

// Adjacent duplicates problem
string rmvdup( string a)
{
    /* time complexity is o(n) space complexity is o(n)
    stack<char> s;
    string ans="";
    for (int i=0 ; i<a.size(); i++)
    {
        if ( s.size()==0){ s.push(a[i]);}
        else if( a[i]!= s.top())
        {
            s.push(a[i]);
        }
        else 
        {
            s.pop();
        }

    }
    while (s.size()>0)
    {
        ans+=s.top();
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans; */

    // simulate inplace stack  time complexity is o(n) and space complexity is o(1)
    int stkptr=-1;
    string ans="";
    for (int i=0 ; i<a.size(); i++)
    {
        if ( stkptr==-1){ 
            stkptr++;
            a[stkptr]=a[i];
        }
        else if( a[i]!= a[stkptr])
        {
            stkptr++;
            a[stkptr]=a[i];
        }
        else 
        {
            stkptr--;
        }

    }
    for (int i =0 ; i<=stkptr; i++)
    {
        ans.push_back(a[i]);
    }
    return ans;
}