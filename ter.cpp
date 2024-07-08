
#include<iostream>
#include<vector>

using namespace std; 

bool isFascinating(int n) {
        
    vector<int> v;
    v.push_back(n/100);
    v.push_back((n/10)%10);
    v.push_back(n%10);
    int m=n*2;
    if(m/100>=10 )
    {
        v.push_back(m/1000);
        v.push_back((m/100)%10);
        v.push_back((m/10)%10);
        v.push_back(m%10);
    }
    else
    {
        v.push_back(m/100);
        v.push_back((m/10)%10);
        v.push_back(m%10);
    }
    n=n*3; 
    if ( n/100>=10)
    {
        v.push_back(n/1000);
        v.push_back((n/100)%10);
        v.push_back((n/10)%10);
        v.push_back(n%10);
    }
    else
    {
        v.push_back(n/100);
        v.push_back(n/10 -(n/100)*10);
        v.push_back(n%10);
    }

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<< " ";
    }
    cout<<endl;
    for(int i=0; i<v.size()-1; i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if (i!=j and v[i]==v[j])
            {
                return false;
            }
            if(v[j]==0) return false;
        } 
    }
    return true; 
        
}
int main()
{
    // int n ;
    // cin>>n; 
    // vector<int> v;
    // v.push_back(n/100);
    // v.push_back(n/10 -(n/100)*10);
    // v.push_back(n%10);
    // n*=2;
    // v.push_back(n/100);
    // v.push_back(n/10 -(n/100)*10);
    // v.push_back(n%10);
    // n*=3; 
    // v.push_back(n/100);
    // v.push_back(n/10 -(n/100)*10);
    // v.push_back(n%10);

    // for(int i=0; i<v.size(); i++)
    // {
    //     cout<<v[i];
    // }

    
    // for (int i=0; i<v.size()-1; i++)
    // {
    //     if ( v[i]==v[i+1] or v[i]==0)
    //     {
    //         cout<<"false"<<endl;
    //         return 0;
    //     }
    // }
    // if( v[v.size()-1] ==0)
    // {
    //     cout<<"false"<<endl;
    //     return 0; 
    // }

    // cout<<"true"<<endl;
    // return 0;

    cout<<isFascinating(192)<<endl;

}