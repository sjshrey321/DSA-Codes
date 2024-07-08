#include<iostream> 
using namespace std; 

int kpRec(int n,vector<int> p, vector<int> w , int wk) // p = prices, w = weights , wk = weigth left ink
{
    // base condition 
    if ( w[n-1]> wk) 
    {
        return kpRec(n-1,p,w,wk); 
    }
    else if (wk == 0)
    {
        return 0 ;
    }
    else if (n==0)
    {
        return 0 ; 
    }
    else 
    {
        int inc = p[n-1] + kpRec(n-1,p,w,wk-w[n-1]); 
        int exc= kpRec(n-1,p,w,wk); 

        return max(inc,exc);  
    }

}

// o(n^2);
int kpdp(int n, vector<int> p, vector<int> w , int wk ){
    int dp[n+1][wk+1];
    for (int i=0; i<=n; i++) 
    {
        for (int j=0; j<=wk; j++)
        if (i==0) return 0; 
        else if (j==0) return 0 ; 
        else if ( w[i-1]>j ) return dp[i-1][j];
        else 
        {
            int inc = p[i-1] + dp[i-1][j-w[i-1]]; 
            int exc = dp[i-1][j];
            dp[i][j]=max(inc,exc);
        }
    }
    return dp[n][0];

}

// using greedy technique we can make it o(nlogn) 
