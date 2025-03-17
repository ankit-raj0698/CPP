class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // create the adjacency list
        for(auto vec: prerequisites){
            int u = vec[0];
            int v = vec[1];
            // v --> u
            adj[v].push_back(u);
        }

        // find the indegree of each vertex
        for(int u = 0; u < numCourses; u++){
            for(auto v : adj[u])
                indegree[v]++;
        }

        queue<int> q;
        // push the vertices whose indegree is 0
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);

            // remove the adjacent edges of u i.e decrease the indegree
            for(int v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        // if we don't have all the courses in ans, it means topo sort not possible
        if(ans.size() != numCourses)
            return {};
        
        return ans;
        
    }
};