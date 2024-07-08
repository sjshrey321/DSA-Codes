// Longest common sequence bw two strings 

#include<iostream> 
#include<string> 
using namespace std; 
// so this is an recursive solution and we have to use dp to mae it better. 
int lcs( string s1, int i, string s2, int j ) 
{
    // base case is when i and j either of them is at the end 
    if ( i== s1.size() || j== s2.size())
    {
        return 0; 
    }
    // case of match

    if( s1[i]== s2[j]) {
        return 1+ lcs(s1,i+1,s2,j+1); 
    }

    // case of mismatch 

    if ( s1[i]!=s2[j]) 
    {
        return max( lcs(s1,i+1,s2,j),lcs(s1,i,s2,j+1)) ; 
        
    }

}

int lcsdp(string s1, string s2){
    // first we initalize an 2d arr 
    int m= s1.size();
    int n = s2.size();
    int dp[m+1][n+1]; 
    // base case 
    for( int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++) 
        {
            if ( i==0 or j==0)
            {
                dp[i][j]=0; 
            }
            else if( s1[i-1]==s2[j-1])
            {
                dp[i][j]= 1+ dp[i-1][j-1]; 

            }
            else if( s1[i-1] != s2[j-1]) {
                dp[i][j]= max(dp[i][j-1],dp[i-1][j-1]);

            }
        }
    }
    int output= dp[m][n]; 
    return output; 
}