Min steps to 1 

steps : 1) dec by one 
        2) div by 2 
        3) div by 3 

// code // 

int minto1( int n ) // using recursion 
// O(k^n)  k on an avg might be 2 but it's not accurate all we know is time complexity is exponential. 
{
    if ( n==1 ) { return 0;}
    else
    {
        if ( n%2!=0 and n%3==0)
        {
            return 1+ min(minto1(n-1),minto1(n/3));
        }
        else if ( n%2==0 and n%3!=0)
        {
            return 1+ min(minto1(n-1),minto1(n/2)); 

        }
        else if ( n%2==0 and n%3==0) 
        {
            return 1+ min( minto1(n-1),min(minto1(n/2),minto1(n/3)));
        }
        else {return 1+ minto1(n-1)};
    }
} 

// using actual DP 
// arr[i] = min steps to reach 1 from i 
// and hence our ans will be arr[n].
// all the arr should be initially be equal to -1. 

// usually like in dp we'll use an array 

// we also use an helper func for avoiding repeatition. 


// { this is top down  method of DP;
int helper(int n; int ans )
{
    if ( n<=1 ) { return 0;}
    else
    {
        if ( ans[n]!=-1 )
        {
            return ans[n]; 
        }
        int x= helper(int n-1,ans);
        int y,z= __INT_MAX__;
        if (n%2=0)
        {
            y= helper(n/2, ans );
        }
        if ( n%3==0)
        {
            y= helper(n/3, ans); 
        }
        int output = min( x, min(y,z))+1; 
        int ans[n]= output; 
        return output 
    }
}

int minto1dp(int n )
{
    // first we'll initiate an arr 
    int *ans;
    for( int i=0; i<=n; i++) // size of the arr will be n+1 ; 
    {
        ans[i]= -1; 
    }
    return helper(n,ans);
}
//} 

// { this is bottum up method of DP ;
// this uses iterative methods ; 

int mainto1i(int n){
    // in this step n steps are save 
    int *dp =new int[n+1];
    dp[0]=0;
    dp[1]=0;
    for ( int i=0 ; i<=n; i++)
    {
        int x= dp[i-1]; 
        int y,z= __INT_MAX__;
        if (i/2!=0) y=dp[i/2];
        if (i/3!=0) z= dp[i/3];
        dp[i]= min(x,min(y,z))+1; // we can replace x,y,z by single var dp[i]; 
    }
    int output = dp[n]; 
    delete []dp;
    return output; 
}
// }