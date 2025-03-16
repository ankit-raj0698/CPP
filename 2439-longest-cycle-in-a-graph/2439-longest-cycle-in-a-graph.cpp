class Solution {
public:
    void dfs(vector<int>& edges, vector<int> &visited, vector<int> &inRecursion, vector<int> &count, int u, int &maxLen){
        visited[u] = 1;
        inRecursion[u] = 1;

        int v = edges[u];
        if(v != -1){
            if(!visited[v]){
                count[v] = count[u] + 1;
                dfs(edges, visited, inRecursion, count, v, maxLen);
            }
            else if(inRecursion[v]){
                // we got a cycle
                maxLen = max(maxLen, count[u] - count[v] + 1);
            }
        }
        inRecursion[u] = 0;
        return;
    }
    int longestCycle(vector<int>& edges) {
        // detect cycle in directed graph
        int n = edges.size();
        vector<int> visited(n,0), inRecursion(n,0);
        // to track count of nodes seen till now
        vector<int> count(n,1);

        int maxLen = -1;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(edges, visited, inRecursion, count, i, maxLen);
            }
        }
        return maxLen;
    }
};