#include<iostream> 
#include<algorithm>
using namespace std; 

// Backtracking is the best possible solution by visiting every possible solution 

/* rat in a maze problem 

in this we are given a matrix of nxn with 1,0 1 means you can travel . 

we have to find every possible solution in lexicography manner. 
*/
bool issafe(int x , int y , vector<vector<bool>> visited, vector<vector<int>> arr, int n )
{
    if((x>=0 && x<n) && (y>=0 && y<n ) && (visited[x][y]!=1 ) && (arr[x][y]==1))
    return true ; 
    return false ; 
}
void maze(int s, int e, int n , vector<vector<int>> &arr ,vector<string> &ans,vector<vector<bool>> &visited, string path)
{
    //base condition 
    if(s==n-1 or e==n-1)
    {
        ans.push_back(path);
        return ; 
    }
    if(issafe(s+1,e,visited, arr, n))
    {
        path+='D'; 
        visited[s+1][e]==true; 
        maze(s+1,e,n,arr,ans, visited,path); 
        visited[s+1][e]==false; 

    }
    if(issafe(s,e-1,visited, arr, n))
    {
        path+='L'; 
        visited[s][e-1]==true; 
        maze(s,e-1,n,arr,ans, visited,path); 
        visited[s][e-1]==false; 

    }
    if(issafe(s,e+1,visited, arr, n))
    {
        path+='R'; 
        visited[s][e+1]==true; 
        maze(s,e+1,n,arr,ans, visited,path); 
        visited[s][e+1]==false; 

    }
    if(issafe(s-1,e,visited, arr, n))
    {
        path+='U'; 
        visited[s-1][e]==true; 
        maze(s-1,e,n,arr,ans, visited,path); 
        visited[s-1][e]==false; 

    }
    return;
    


}

