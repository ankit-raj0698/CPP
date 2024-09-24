class Solution {
public:
    // when you closely look the example you will realise that all the states which are part of cycle are not safe
    bool dfsCycle(vector<vector<int>>& graph, int u, vector<int> &visited, vector<int> &inRecursion){
        visited[u] = 1;
        inRecursion[u] = 1;

        for(int v: graph[u]){
            if(!visited[v]){
                if(dfsCycle(graph, v, visited, inRecursion))
                    return true;
            }
            else if(inRecursion[v])
                return true;
        }


        inRecursion[u] = 0;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> inRecursion(n,0);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfsCycle(graph, i, visited, inRecursion);
            }
        }

        // states which are not part of cycle are safe states
        // if inRecursion of a node is false it means it is not part of cycle
        vector<int> safeState; 
        for(int i = 0; i < n; i++){
            if(inRecursion[i] == 0)
                safeState.push_back(i);
        }
        
        return safeState;
        
    }
};