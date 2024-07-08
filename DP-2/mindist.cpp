// minimum distance problem or edit distance problem 
#include<iostream> 
using namespace std; 

/*
there'll be given two words and we need to convert the first word into word 2
we can use 3 alterations : 
1; insert a char
2; delete a char
3; replace a char 

and we need the min steps to do this operation
*/ 

// recurersion method 

// in this method recursion can be used like this 
// if we have to delete a string then str1 will have one less size 
int mind(string s1, int m, string s2, int n) 
{
    // first of all the case that one of the string is empty 
    if ( m == 0) return n; 
    if ( n==0 ) return m ; 
    // now the base case 
    if( s1[m-1]= s2[n-1]) return mind(s1,m-1, s2, n-1) ; 
    else 
    {
        int insert = mind(s1,m,s2,n-1);
        int dlt = mind(s1,m-1,s2, n);
        int replace = mind(s1,m-1,s2,n-1);

        return 1+min(insert,min(dlt,replace));
    }
}

// now'll be using into dp code 

int mindp(string s1,string s2) 
{
    int m = s1.size(); 
    int n = s2.size(); 
    // we'll initialize an 2d array 

    // in this dp array i,j represents mind of i lenths and j length of both words 
    int dp[m+1][n+1];
    // case of emptiness 
    for (int i=0; i<=m; i++) 
    {
        for (int j=0; j<=n; j++) 
        {
            if ( i==0 ) 
            {
                dp[i][j]=j;
            }
            else if (j==0) 
            {
                dp[i][j]= i; 
            }
            else 
            {
                if (s1[i-1]==s2[j-1])
                {
                    dp[i][j]= dp[i-1][j-1]; 
                }
                else
                {
                    int insert= dp[i][j-1]; 
                    int dlt = dp[i-1][j]; 
                    int replace=dp[i-1][j-1]; 
                    
                    dp[i][j]=1+ min( insert, min(dlt,replace));
                }
            }
        }
        

    }
    return dp[m][n];
}