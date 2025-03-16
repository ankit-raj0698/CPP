class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int u, int currColor){
        color[u] = currColor;
        
        for(int v: graph[u]){
            if(color[v] == -1){
                if(dfs(graph, color, v, 1 - currColor) == false)
                    return false;
            }
            else if(color[v] == currColor)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // adj list, color vector, curr, currColor
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(dfs(graph, color, i, 0) == false)
                    return false;
            }
        }
        return true;
    }
};