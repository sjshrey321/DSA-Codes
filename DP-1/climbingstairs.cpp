#include<iostream>
using namespace std;

// question is how many ways to climb to the top when you can either take one steap or two in a single step ; 
int cs(int n)
{
    int *dp= new int[n+1]; 
    dp[1]= 1; 
    dp[2]= 2;
    for(int i=3; i<= n; i++){
        dp[i]=dp[i-1] + dp[i-2]; 
    }
    int output= dp[n]; 
    delete []dp;
    return output; 

}

// let's solve for gen steps taken in single time say 'k' ; 
int csgen(int n, int k)
{
    int *dp= new int[n+1] ; 
    dp[0]=1;
    dp[1]=1;
    for (int i= 2; i<=n ; i++)
    {
        for(int j= 1; j<=k;j++)
        {
            dp[i]+=dp[i-j];
        }
    }
    int output= dp[n]; 
    delete []dp; 
    return output ;
}

int main() 
{
    cout<<csgen(5,2)<<endl;
}