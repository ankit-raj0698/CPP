class Solution {
public:
    
    bool topoSort(unordered_map<int, vector<int>> &adj,int numCourses, vector<int> &indegree){
        queue<int> q;
        
        int count = 0;
        // when indegree of a node is 0, push it in queue and increment the count
        for(int i = 0; i < numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()){
            // find the front node
            int u = q.front();
            q.pop();
            
            // visit the neighbour of front node and decrement the indegree of neighbours
            for(int v : adj[u]){
                indegree[v]--;
                // when indegree of a node is 0, push it in queue and increment the count
                if(indegree[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }
        // if cycle doesn't exist so courses can be done so return true
        if(count == numCourses){
            return true;
        }
       
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses,0);
        
        // create the adjacency list 
        for(vector<int> vec: prerequisites){
            int u = vec[0];
            int v = vec[1];
            // 1--->0
            adj[v].push_back(u);
            indegree[u]++;         
        }
      return topoSort(adj, numCourses,indegree);
    }
};