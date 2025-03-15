class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        typedef pair<long long, long long> t;
        long long mod = 1e9 + 7;
        vector<vector<t>> adj(n); 

        // create the adjacency list
        for(auto vec: roads){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        // we need pq, dist vector, ways vector
        priority_queue<t, vector<t>, greater<t>> pq;
        vector<long long> dist(n, 1e12), ways(n, 0);

        // push {dist[src], src} to pq
        // src = 0, dest = n - 1
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1; // there is only 1 way to reach src

        while(!pq.empty()){
            auto [du, u] = pq.top();
            pq.pop();

            for(auto [v, wt]: adj[u]){
                if(du + wt < dist[v]){
                    // this is the first time we are getting min dist
                    dist[v] = du + wt;
                    pq.push({dist[v], v});
                    ways[v] = ways[u] % mod;
                }
                else if(du + wt == dist[v]){
                    // through another path, we are getting same min dist to reach v
                    // so just update the ways
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n-1] % mod;

    }
};