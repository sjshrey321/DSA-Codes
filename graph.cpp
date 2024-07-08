#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue> 
#include<list>


using namespace std; 
// edge list method 
//(very bad way of implementing because even a simple query like checking 
// a edge bw two nodes have o(n^2); 
class graph{
    // list of vertices 


    // list of edges 

    
};

// adjecenty list


// implementing adjecentcy list 

int main()
{
    int n,e; 
    cin>> n>>e;

    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i = 0; i<n;i++)
    {
        int fv,sv;
        cin>>fv>>sv;
        matrix[fv][sv]= 1;
        matrix[fv][sv]= 1; 

    }
    return 0 ; 
    
}

// kruksal algorithm 

// we need three funtions : makeset() , find(), union() . 

void makeset(vector<int> &parent,vector<int> &rank)
{
    for(int i =0 ; i<parent.size();i++)
    {
        parent[i]=i;

    }
    for(int i =0 ; i<parent.size();i++)
    {
        rank[i]=0 ;
    }
}

int  Find(vector<int> parent, int i)
{
    while(parent[i]!= i)
    {
        i=parent[i]; 
    }
    return i ;
}

void Union(vector<int> parent, vector<int> rank,int x,int y )
{
    int a = Find(parent,x);
    int b = Find(parent,y ); 
    if(rank[a]<rank[b])
    {
        parent[a]= b; 
    }
    if (rank[b]< rank[a])
    {
        parent[b]= a; 
    }
    if(rank[a]== rank[b])
    {
        parent[b]=a;
        rank[a]++;

    }

}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2]<b[2];
}

int mst_kruksal( vector<vector<int>> edge,int n)// g will be int nx3 where 3 column 0:link 1 , 1: link2 , 2:wt
{

    int minwt=0; 
    sort(edge.begin(),edge.end(),cmp);  // sorting on basis of wt ;
    vector<int> parent(n); 
    vector<int> rank(n,0);
    makeset(parent,rank);
    for(int i= 0; i<edge.size(); i++)
    {
        int u = Find(parent,edge[i][0]);
        int v= Find(parent,edge[i][1]);

        if(u!=v )
        {
            minwt+=edge[i][2];    
            Union(parent, rank, u,v);
        }
    }
    return minwt; 


}

// prim's algorithm 


vector<pair<pair<int,int>,int>> mst_prims(int n , int m , vector<pair<pair<int,int>,int>> g)
{
    // create adj list ; 

    unordered_map<int, list<pair<int,int>>> adj;

    for(int i =0 ; i<=n;i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second; 
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }

    // create parents, key , visited vectors

    vector<int> parent(n+1,-1);
    vector<int> key(n+1,INT_MAX);
    vector<bool> visited(n+1,false);

    // o(n2) approach  

    key[1]=0;
    parent[1]=-1;

    for(int i=1 ; i<n; i++)
    {
        // we maintain the mini for the minimum weight in all the vertices ; 

        int mini = INT_MAX; 
        int u ; 

        for(int v = 1 ; v<=n ; v++)
        {
            if(visited[v]==false and key[v]<mini)
            {
                mini=key[v];
                u=v;
            }

        }

        visited[u] = true; 
        
        // adj vertices ; 

        for( auto it: adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(visited[v]== false and   w< key[v])
            {
                parent[v] = u ; 
                key[v] = w; 
                 
            }
        }
    }
    vector<pair<pair<int,int>,int>> result; 
    for(int i = 2; i<=n ; i++)
    {
        result.push_back( {{parent[i],i},key[i]});

    }
    return result; 

}

// bipartism { can we colour the graph in two colour so that the adjacent nodes don't have the same colour 
bool check(int sv,int e , vector<int> adj[],int  colour[])
{
    queue<int> q; 
    q.push(sv);
    colour[sv]= 0 ; 
    while(!q.empty())
    {
        int f = q.front(); 
        q.pop(); 
        for(auto i : adj[f])
        {
            if(colour[i]==-1) 
            {
                if(colour[f]==0) colour[i]=1 ; 
                else colour[i]=0  ; 
                q.push(i); 
            }
            else if (colour[f]==colour[i]) return false; 
        }
    } 
    return true ;     
}
bool isBipart(int e,vector<int> adj[])
{
    int colour[e]; 
    for(int i =0;i<e;i++) colour[i]=-1; 
    for(int i = 0 ; i<e;i++)
    {
        if(colour[i]==-1)
        {
            if(check(i,e,adj,colour)==false) return false; 
        }
    }
    return true; 
}
