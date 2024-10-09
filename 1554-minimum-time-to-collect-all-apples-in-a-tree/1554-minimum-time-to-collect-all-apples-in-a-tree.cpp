class Solution {
public:

    int dfs(unordered_map<int, vector<int>> &adj, int src, int parent,vector<bool>& hasApple){
        int time = 0;
        for(int child: adj[src]){
            // agar neighbour node parent hi h to skip kr do
            if(child == parent)
                continue;
            // ask child to return time taken to find apple
            int timeByChild = dfs(adj, child, src, hasApple);
            // if child apple find kr le rha ya child ke pas hi apple hai 
            if(timeByChild > 0  || hasApple[child]){
                time += timeByChild + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec: edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj, 0, -1, hasApple);
        
    }
};