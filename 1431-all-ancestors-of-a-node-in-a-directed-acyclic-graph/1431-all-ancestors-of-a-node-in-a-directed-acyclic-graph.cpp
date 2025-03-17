class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int u, int ancestor, vector<vector<int>> &ans){
        visited[u] = 1;
        if(u != ancestor){
            ans[u].push_back(ancestor);
        }

        for(int v: adj[u]){
            if(!visited[v])
                dfs(adj, visited, v, ancestor, ans);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);

        for(auto vec: edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            vector<int> visited(n,0);
            int ancestor = i;
            dfs(adj, visited, i, ancestor,ans);
        }

        return ans;
    }
};