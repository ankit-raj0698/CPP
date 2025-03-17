class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &visited, vector<int> &inRecursion, int u){
        visited[u] = 1;
        inRecursion[u] = 1;

        for(int v: graph[u]){
            if(!visited[v]){
                if(dfs(graph, visited, inRecursion, v))
                    return true;
            }
            else if(inRecursion[v])
                return true;
        }
        inRecursion[u] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // those nodes are safe which are not part of cycle
        // using DFS we can find the nodes which are part of cycle 
        // inRecursion vector will tell us about the nodes which are part of cycle 

        int n = graph.size();
        vector<int> visited(n,0) , inRecursion(n, 0);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                // call DFS
                dfs(graph, visited, inRecursion, i);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(inRecursion[i] == 0){
                // ith node is not part of cycle
                ans.push_back(i);
            }
        }
        return ans;
    }
};