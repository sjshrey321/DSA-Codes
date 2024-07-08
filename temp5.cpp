#include<iostream>
#include<vector>
#include<climits>
using namespace std; 

// recursive
int stopsrec(int i,int prev, int target, int fuel, vector<vector<int>>& stations) {
    //i is the index ; 
    if (target<fuel) return 0 ; // this should be first because target <fuel 
    // at n= stations.size() then we return 0 before if not then -1 ;
    if( i== stations.size()) return INT_MAX -1 ; // why INT_MAX-1;


    int dist= stations[i][0]-prev; 
    if ( fuel < dist) return INT_MAX-1 ; 

    int take = stopsrec(i+1, stations[i][0], target-prev,fuel - dist + stations[i][0],stations);
    int not_take= stopsrec(i+1, prev, target ,fuel, stations);

    return min(take,not_take);

    }

int stopdp(int target , int fuel, vector<vector<int>> stations){
    int n = stations.size(); 
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));

    dp[0][0] = 0;
    
}
int main()
{
    int target =100;
    int startFuel= 10 ; 
    vector<vector<int>> stations; 
    for (int i =0 ; i<4 ; i++)
    {
        cin>>stations[i][0];
        cin>>stations[i][1];
    }
    return 0 ; 
}