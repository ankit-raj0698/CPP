class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int,int>>> &adj, vector<int> &visited, int u, int &count){
        visited[u] = 1;
        for(auto p: adj[u]){
            int v = p.first;
            int awayFromZero = p.second;
            if(!visited[v]){
                if(awayFromZero == 0)
                    count++;
                dfs(adj, visited, v, count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int,int>>> adj;
        vector<int> visited(n, 0);

        for(auto vec: connections){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }

        int count = 0;
        dfs(adj, visited, 0, count);
        return count;
        
    }
};