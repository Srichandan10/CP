#include <bits/stdc++.h>
using namespace std;



class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
    stack<int> st;
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++){
	        if(vis[i]==false){
	            dfs(i,adj,vis);
	        }
	    }
	    while(st.empty()==false){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	}
	void dfs(int n,vector<int> adj[],vector<bool> &vis){
	    vis[n]=true;
	    for(auto nb:adj[n]){
	        if(!vis[nb]){
	            dfs(nb,adj,vis);
	        }
	    }
	    st.push(n);
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


int main() {
	file_i_o();
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        for(int i=0;i<res.size();i++){
        	cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}  