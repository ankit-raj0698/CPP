class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, int u, vector<bool> &visited,int n){
        visited[u] = true;
        // find the neighbours of u, here u => row so traverse all the column for row u
        for(int v = 0; v < n ; v++){
            if(!visited[v] && isConnected[u][v] == 1){
                dfs(isConnected, v , visited, n);
            }
        }
    }
    
    void bfs(vector<vector<int>>& isConnected, int curr, vector<bool> &visited,int n){
        queue<int> q;
        
        q.push(curr);
        visited[curr] = true;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int v = 0; v < n; v++){
                if(!visited[v] && isConnected[u][v] == 1){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false); 
            
        int count = 0;
        for(int i = 0; i < n ; i++){
            if(!visited[i]){
               //dfs(isConnected, i, visited,n);
                bfs(isConnected, i, visited,n);
                count++;
            }
        }
      return count;  
    }
    
    /*
    // using custom created adjacency list
    void dfs(unordered_map<int,vector<int>> adj, int u, vector<bool> &visited){
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                dfs(adj, v , visited);
            }
        }
    } 
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n,false); 
            
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n ; j++){
               if(isConnected[i][j] == 1){
                   adj[i].push_back(j);
                   adj[j].push_back(i);
               } 
            }       
        }
        
        int count = 0;
        for(int i = 0; i < n ; i++){
            if(!visited[i]){
               dfs(adj, i, visited);
                count++;
            }
        }
      return count;  
    }
    */
    
};