class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        unordered_map<int, vector<pair<int,int>>> adj;
        // Create adjacency list with colors: 1 for red, 2 for blue
        for(auto vec: redEdges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back({v, 1});
        }

        for(auto vec: blueEdges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back({v, 2});
        }

        // Separate visited arrays for red and blue
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<int> dist(n, -1);

        // Queue stores: {node, current distance, last edge color}
        queue<vector<int>> q;
        q.push({0, 0, -1}); // Start at node 0 with distance 0 and no last edge color
        dist[0] = 0;

        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            int u = vec[0];
            int d = vec[1];
            int color = vec[2]; // Last edge color used

            for(auto p : adj[u]){
                int v = p.first;
                int currColor = p.second;

                // If the color of the edge is different from the last used and the node hasn't been visited with this color
                if (!visited[v][currColor - 1] && currColor != color) {
                    visited[v][currColor - 1] = true;
                    q.push({v, d + 1, currColor});

                    // Update distance if it's the first time reaching this node
                    if (dist[v] == -1) {
                        dist[v] = d + 1;
                    }
                }
            }
        }

        return dist;
    }
};
