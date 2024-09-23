class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        

        queue<pair<int,int>> q;
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        // push all rotten oranges in queue so that they can work simultaneously 
        // when we use BFS
        // count the fresh oranges as well
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;
        
        while(!q.empty()){
            int size = q.size();
            bool rot = false;
            // since we want all rotten orange to work simultaneously, use all oranges of
            // current level then only move to next level
            for(int k = 0; k < size; k++){
                auto front = q.front();
                q.pop();

                int curr_i = front.first;
                int curr_j = front.second;

                for(auto dir: direction){
                    int row = curr_i + dir.first;
                    int col = curr_j + dir.second;

                    // when we are in the grid and have fresh orange
                    // update it to rotten and push the rotten orange in queue
                    if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1){
                        grid[row][col] = 2;
                        fresh--;
                        rot = true;
                        q.push({row, col});
                    }
                }
            }
            // when we have explored all cells of current level, and we have rotten some
            // orange during this, then increment time
            if(rot)
                time++;
        }

        if(fresh > 0)
            return -1;

        return time;
        
    }
};