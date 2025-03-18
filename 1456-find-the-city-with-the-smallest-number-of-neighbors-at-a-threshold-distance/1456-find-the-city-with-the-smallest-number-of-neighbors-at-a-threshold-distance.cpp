class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // create the dist matrix with edge weights
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        for(auto vec: edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // find the all pair shortest path
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][via] != 1e9 && dist[via][j] != 1e9){
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        // Traverse the all pair shortest path dist matrix to check threshold
        int maxCityTravelled = 1e9;
        int city = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt <= maxCityTravelled){
                maxCityTravelled = cnt;
                city = i;
            }
        }
        return city;
    }
};