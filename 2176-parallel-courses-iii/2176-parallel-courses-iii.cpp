class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        queue<int> q;

        // we have 1 based graph, so convert it to 0-based
        // fill the indegree vector while preparing the adjacency list
        for(auto vec: relations){
            int u = vec[0] - 1;
            int v = vec[1] - 1;

            adj[u].push_back(v);
            indegree[v]++;
        }
        
        vector<int> maxTime(n,0);
        // push the node whose indegree = 0 in q and update maxTime
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
                maxTime[i] = time[i];
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: adj[u]){
                indegree[v]--;
                
                // to calculate the maxTime from u to v
                // we consider maxTime to reach u + original time to reach v
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);

                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        
        return *max_element(maxTime.begin(), maxTime.end());
    }
};