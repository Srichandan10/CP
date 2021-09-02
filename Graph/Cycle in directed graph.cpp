#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool> visited(V,false);
	   	vector<bool> rec(V,false);
	   	for(int i=0;i<V;i++){
	   	    if(visited[i]==false && cycle(i,adj,visited,rec)==true){
	   	        return true;
	   	    }
	   	}
	   	return false;
	   	
	}
	bool cycle(int n,vector<int> adj[],vector<bool> &visited,vector<bool> &rec){
	    visited[n]=true;
	    rec[n]=true;
	    for(auto nb:adj[n]){
	        if(visited[nb]==false && cycle(nb,adj,visited,rec)==true){
	            return true;
	        }
	        else if(rec[nb]==true){
	            return true;
	        }
	    }
	    rec[n]=false;
	    return false;
	}
};

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}


int main()
{
    file_i_o();
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
