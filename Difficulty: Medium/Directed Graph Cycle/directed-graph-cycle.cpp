//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
	    queue<int> q;
	    vector<int> ans;
	    
	    // find the indegree of each node
	    for(int u = 0; u < V; u++){
	        for(int &v: adj[u]){
	            indegree[v]++;
	        }
	    }
	    
	    // push the nodes whose indegree is 0
	    for(int u = 0; u < V; u++){
	        if(indegree[u] == 0)
	            q.push(u);
	    }
	    
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        ans.push_back(front);
	        
	        // since we have processed the front node so remove the adjacent edges
	        // and its degree
	        for(int &v: adj[front]){
	            indegree[v]--;
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    if(ans.size() == V)
	        return false;
	    else
	        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends