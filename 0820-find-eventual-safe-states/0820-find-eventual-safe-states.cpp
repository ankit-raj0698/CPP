class Solution {
public:
    
    // to detect nodes that are part of cycle  , check inRecursion vector
    // cycle nodes will have inRecursion[i] value = true
    
    bool dfsCycleDirected(vector<vector<int>>& graph, int u, vector<bool> &visited, vector<bool> &inRecursion){
        
        visited[u] = true;
        inRecursion[u] = true;
        
        for(int v : graph[u]){
            if(!visited[v]){
                if(dfsCycleDirected(graph, v, visited, inRecursion))
                    return true;
            }
            else if(inRecursion[v] == true)
                return true;
        }
        inRecursion[u] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<bool> inRecursion(n,false);
        
        for(int i = 0; i < n; i++){
            
            if(!visited[i]){
                dfsCycleDirected(graph, i, visited, inRecursion);
            } 
        }
        
        // inRecursion vector whose value is false are not part of cycle and hence safe
        vector<int> safeState; 
        for(int i = 0; i < n; i++){
            if(inRecursion[i] == false)
                safeState.push_back(i);
        }
        
        return safeState;
    }
};