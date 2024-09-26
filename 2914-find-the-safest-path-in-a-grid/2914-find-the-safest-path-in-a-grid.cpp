class Solution {
public:
    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n;

    bool check(vector<vector<int>> &dist, int safeFactor){
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(n,0));
        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            if(dist[0][0] < safeFactor)
                return false;

            for(auto dir: direction){
                int row = i + dir.first;
                int col = j + dir.second;


                if(row >= 0 && row < n && col >= 0 && col < n && !visited[row][col] && dist[row][col] >= safeFactor){
                    if(row ==  n-1 && col == n-1)
                        return true;
                    q.push({row,col});
                    visited[row][col] = 1;
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n,-1));
        vector<vector<int>> visited(n, vector<int>(n,0));

        // find the dist of every cell from nearest thief so use multi-source BFS
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){

                auto [i,j] = q.front();
                q.pop();

                dist[i][j] = level;

                for(auto dir: direction){
                    int row = i + dir.first;
                    int col = j + dir.second;

                    if(row >= 0 && row < n && col >= 0 && col < n && !visited[row][col]){
                        q.push({row,col});
                        visited[row][col] = 1;
                    }
                }
            }
            level++;
        }

        int low = 0, high = level-1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(dist,mid)){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        
        return ans;

        
    }
};