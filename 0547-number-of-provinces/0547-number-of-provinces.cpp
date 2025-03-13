class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int> &visited, int u){
        visited[u] = 1;
        for(int v = 0; v < isConnected.size(); v++){
            if(isConnected[u][v] && !visited[v])
                dfs(isConnected, visited, v);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};