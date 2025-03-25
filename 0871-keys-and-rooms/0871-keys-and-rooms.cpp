class Solution {
public:
    // standard DFS code
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int u){
        visited[u] = 1;
        for(int v: adj[u]){
            if(!visited[v])
                dfs(adj, visited, v);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        

        // create the adjacency list
        for(int u = 0; u < n; u++){
            for(int v: rooms[u]){
                adj[u].push_back(v);
            }
        }

        // start the dfs from room no 0 and count no. of components in graph
        vector<int> visited(n, 0);
        int noOfComponent = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                noOfComponent++;
                if(noOfComponent > 1)
                    return false;
            }
        }
        return true;
    }
};