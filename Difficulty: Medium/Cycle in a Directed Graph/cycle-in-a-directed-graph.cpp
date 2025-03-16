//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<vector<int>>& adj, vector<int> &visited,int u, vector<int> &inRecursion){
        visited[u] = 1;
        inRecursion[u] = 1;
        
        for(int v: adj[u]){
            if(!visited[v]){
                if(dfs(adj, visited, v, inRecursion))
                    return true;
            }
            else if(inRecursion[v])
                return true;
        }
        inRecursion[u] = 0;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> visited(n,0), inRecursion(n, 0);
        
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(adj, visited, i, inRecursion))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends