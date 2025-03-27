//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(V,0);
        
        int sum = 0;
        pq.push({0,0});
        
        while(!pq.empty()){
            //auto [du, u] = pq.top();
            pair<int,int> temp = pq.top();
            int du = temp.first;
            int u = temp.second;
            pq.pop();
            
            if(visited[u])
                continue;
            sum += du;
            visited[u] = 1;
            
            for(auto p: adj[u]){
                int v = p[0];
                int wt = p[1];
                if(!visited[v]){
                    pq.push({wt, v});
                }
            }
        }
        
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends