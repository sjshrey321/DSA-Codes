//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int scr ,int V,vector<int> adj[],vector<int> &colour)
    {
	    queue<int> q; 
	    q.push(scr); 
	    colour[scr] = 0 ; 
	    while(!q.empty())
	    {
	        int f = q.front(); 
	        q.pop(); 
	        for(auto i : adj[f])
	        {
	            if(colour[i]==-1)
	            {
	                if(colour[f] == 0 ) colour[i]=1; 
	                else colour[i]= 0 ; 
	                q.push(i) ; 
	               
	            }
	            else if(colour[i]==colour[f]) return false; 
	        }
	    }
	    return true; 
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colour(V,-1) ; 
	    for(int i = 0 ; i<V; i++) 
	    {
	        if(colour[i]==-1 )
	        {
	           bool ans = check(i,V,adj,colour);
	           if (!ans) return false;
	        }
	        
	    }
	    return true ;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends