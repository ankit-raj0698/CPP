class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        typedef pair<int,int> t;
        unordered_map<int, vector<t>> adj;

        // create the adjacency matrix
        for(auto vec: times){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<t, vector<t>, greater<t>> pq;
        vector<int> dist(n+1, 1e9);

        // push the dist, src in priority_queue
        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()){
            auto [du, u] = pq.top();
            pq.pop();

            for(auto [v,wt]: adj[u]){
                if(du + wt < dist[v]){
                    dist[v] = du + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = -1;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dist[i]);
        }

        return ans == 1e9 ? -1 : ans;

        
    }
};