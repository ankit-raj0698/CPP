class Solution {
public:

    void dfs(vector<int>& edges, int node, vector<int> &dist, vector<bool> &visited){
        visited[node] = true;
        int v = edges[node];
        if(v != -1 && !visited[v]){
            dist[v] = 1 + dist[node];
            dfs(edges, v, dist, visited);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);

        int minDistTillNow = INT_MAX;
        int minDistNode = -1;

        for(int i = 0; i < n;  i++){
            int maxDist = max(dist1[i], dist2[i]);

            if(maxDist < minDistTillNow){
                minDistTillNow = maxDist;
                minDistNode = i;
            }
        }
        return minDistNode;
    }
};