class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        typedef pair<int,pair<int,int>> t;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        vector<pair<int,int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0},
                                {1,1}, {1,-1}, {-1,1}, {-1,-1}};
            
        priority_queue<t, vector<t>, greater<t>> pq;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // we are also considering cell (0,0) for dist
        pq.push({1,{0,0}});
        dist[0][0] = 1;

        while(!pq.empty()){
            
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i == n-1 && j == n-1)
                return dist[i][j];
                
            for(auto dir: direction){
                int row = i + dir.first;
                int col = j + dir.second;

                if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0 && (d + 1 < dist[row][col])){
                    dist[row][col] = d + 1;
                    pq.push({dist[row][col] ,{row, col}});
                    
                    }
                }
        }
        return -1;
    }
};