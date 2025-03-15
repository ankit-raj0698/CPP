class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<int> &visited, int u){
        visited[u] = 1;
        for(int v: adj[u]){
            if(!visited[v])
                dfs(adj, visited, v);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int>> adj;
        int n = rooms.size();

        for(int u = 0; u < n; u++){
            for(int v: rooms[u]){
                adj[u].push_back(v);
            }
        }

        vector<int> visited(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                count++;
                if(count > 1)
                    return false;
            }
        }
        return true;
    }
};