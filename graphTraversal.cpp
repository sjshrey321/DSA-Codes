#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include"graph.cpp"

using namespace std; 

void printDFS(vector<vector<int>> v, int sv, vector<bool> &visited)
{
    // we have to maintain an array of vertices so that we do not visit again and again 
    // and end up being stuck in an infinite loop. 
    cout<<sv<<endl; // sv print 
    visited[sv]=true;
    int n= v.size();
    for(int i = 0 ; i<n ; i++)
    {
        if(v[sv][i]==1 && visited[i]==false ) // link present and should not visit twice
        {
            printDFS(v,i,visited);
        }
    }


}

// now we add another function so that we have it functioning for disconnected graphs. 
void DFS(vector<vector<int> > matrix)
{
    int n =matrix.size();
    vector<bool> visited(n,false);

    for(int i =0 ;i<n; i++)
    {
        if(visited[i]==false)
        {
            printDFS(matrix,i,visited);
        }
    }
}

// 
void printBFS(vector<vector<int> f> matrix,int sv, vector<bool> &visited)
{
    int n = matrix.size();
    // vector<bool> visited(n,false);
    queue<int> q; 
    q.push(sv); 
    visited[sv]=true ;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        cout<<f<<endl;
        for(int i = 0 ; i<n; i++)
        {
            if(matrix[f][i]==1 and visited[i]==false)
            {
                q.push(i);
                visited[i]= true; 

            }
        }
    }

}

void BFS(vector<vector<int>> matrix)
{
    int n =matrix.size();
    vector<bool> visited(n,false);

    for(int i =0 ;i<n; i++)
    {
        if(visited[i]==false)
        {
            printBFS(matrix,i,visited);
        }
    }
}
 

int main()
{
    int n,e; 
    cin>>n>>e; 

    vector<bool> visited(n,false);
    cout<<string(2,'v'); 



}
