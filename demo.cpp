#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int helper(vector<int> nums, int target,int f, int to)
{
    if(f>=to) return 0;
    if(abs(nums[f]-nums[f+1])<=target)
    {
        int inc=1+helper(nums,target, to,to+1); // condition 
        int exc = helper(nums,target,f,to);
        ans=max(inc,exc);
    }
    else
    {
        ans=helper(nums,target,f,to+1);
    }

    if(ans!=0) return ans;
    return -1;

    
}

int maximumJumps(vector<int>& nums, int target) {
    int n = nums.size(); 
    vector<int> dp(n,-1); 
    dp[0]= 0 ;
    for(int i = 1 ; i<n ; i++)
    {
        for(int j= 0 ; j<i; j++)
        {
            if(abs(nums[i]-nums[j])<=target and dp[j]!=-1)
            {
                dp[i]= max(dp[i],dp[j]+1); 
            }
        }
    }
    return dp[n-1]; 
    
}

int main()
{
    vector<int> nums(6);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    cout<<helper(nums,2,0,5);
    
}



