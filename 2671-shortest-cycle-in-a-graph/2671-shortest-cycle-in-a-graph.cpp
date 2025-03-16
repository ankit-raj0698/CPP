class Solution {
public:
    void bfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &dist, int src, int &minLen) {
        
        queue<pair<int, int>> q;
        q.push({src,-1});
        dist[src] = 0;
        visited[src] = 1;

        while(!q.empty()){
            auto [u,parent] = q.front();
            q.pop();

            for(int v: adj[u]){
                if(!visited[v]){
                    dist[v] = 1 + dist[u];
                    visited[v] = 1;
                    q.push({v, u});
                }
                else if(v != parent){
                    minLen = min(minLen, dist[v] + dist[u] + 1);
                }
            }
        }    
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<vector<int>> adj(n);
        for (auto vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int minLen = INT_MAX; // Initialize to maximum possible value

        for(int i = 0; i < n; i++){
            vector<int> visited(n,0);
            vector<int> dist(n, 1e9);

            bfs(adj, visited, dist, i, minLen);
        }
        

        return minLen == INT_MAX ? -1 : minLen; // Return -1 if no cycle is found
    }
};