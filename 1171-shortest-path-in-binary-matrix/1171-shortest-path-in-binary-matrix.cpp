class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Special case: If the grid is 1x1 and the cell is 0, return 1
        if(n == 1 && grid[0][0] == 0) 
            return 1;

        // If start or end cell is blocked, return -1
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        // Initialize BFS
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<pair<int, int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,-1}, {-1,1}, {1,1}, {1,-1}};

        q.push({0, 0});
        visited[0][0] = 1;  // Mark the start as visited

        int time = 1;  // Time is the path length, starting at 1

        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                auto [i, j] = q.front();
                q.pop();

                // Check all 8 directions
                for(auto &dir: direction) {
                    int row = i + dir.first;
                    int col = j + dir.second;

                    // Check if within bounds and not visited
                    if(row >= 0 && row < n && col >= 0 && col < n && !visited[row][col]) {
                        // If we've reached the bottom-right corner
                        if(row == n-1 && col == n-1)
                            return ++time;  // Return current time as path length

                        // If it's a valid cell (grid[row][col] == 0)
                        if(grid[row][col] == 0) {
                            visited[row][col] = 1;
                            q.push({row, col});
                        }
                    }
                }
            }

            time++;  // Increment the time (path length) after processing each level
        }

        // If no path is found, return -1
        return -1;
    }
};
