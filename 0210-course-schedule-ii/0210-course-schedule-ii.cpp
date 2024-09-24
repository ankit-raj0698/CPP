class Solution {
public:

    // if topological sort is possible then ans true otherwise {}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // map to store adjacency list
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        vector<int> ans;
        queue<int> q;

        for(auto &vec: prerequisites){
            int u = vec[0];
            int v = vec[1];
            // [ai, bi] => bi -> ai
            adj[v].push_back(u);
            indegree[u]++;
        }

        // push all the nodes in queue whose indegree is 0
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);

            // decrease the indegree of adj[u]
            for(int v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        // when topological sort is possible
        if(ans.size() == numCourses)
            return ans;
        
        return {};
    }
};