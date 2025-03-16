//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<vector<int>>& adj, vector<int> &visited,
                int u, int parent){
        
        visited[u] = 1;
        for(int v: adj[u]){
            if(!visited[v]){
                if(dfs(adj, visited, v, u))
                    return true;
            }
            else if(parent != v)
                return true;
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> visited(n,0);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(adj, visited, i, -1))
                    return true;
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends