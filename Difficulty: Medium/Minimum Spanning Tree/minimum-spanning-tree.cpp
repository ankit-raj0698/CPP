//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<int> parent;
    vector<int> rank;
    
    struct comparator{
        bool operator()(vector<int> &v1, vector<int> &v2){
            return v1[2] < v2[2];
        }
    };
    
    int find(int x){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void dsu(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);
        
        if(parent_u != parent_v){
            if(rank[parent_u] > rank[parent_v])
                parent[parent_v] = parent_u;
            else if(rank[parent_v] > rank[parent_u])
                parent[parent_u] = parent_v;
            else{
                parent[parent_u] = parent_v;
                rank[parent_v]++;
            }
        }
    }
    
    int kruskals(vector<vector<int>> &vec){
        int sum = 0;
        for(auto temp: vec){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            // u, v are in different component so do a union of them
            if(parent_u != parent_v){
                dsu(u,v);
                sum += wt;
            }
        }
        return sum;
    }
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        // store u,v,wt from adj list in a vector so that we can sort acc to edge wt
        vector<vector<int>> vec;
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i = 0; i < V; i++)
            parent[i] = i;
        
        for(int u = 0; u < V; u++){
            for(auto temp: adj[u]){
                int v = temp[0];
                int wt = temp[1];
                
                vec.push_back({u, v, wt});
            }
        }
        // sort the edges acc to wt
        sort(vec.begin(), vec.end(), comparator());
        
        // call kruskals
        return kruskals(vec);
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