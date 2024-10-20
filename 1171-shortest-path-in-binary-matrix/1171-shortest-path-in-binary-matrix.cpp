class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // when source or dest is not vacant
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<pair<int,int>> direction = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,1}, {-1,-1}, {1,-1}};
        queue<pair<int, int>> q;

        // push the source in queue & mark it visited
        q.push({0,0});
        visited[0][0] = 1;

        // since we are counting the source cell as well in path length so start from 1
        int level = 1;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                // find the co-ordinates of current cell to be popped
                auto [i,j] = q.front();
                q.pop();

                // if current cell is destination then return level
                if(i == n-1 && j == n-1)
                    return level;

                // explore all 8 directions
                for(auto dir: direction){
                    int row = i + dir.first;
                    int col = j + dir.second;

                    // within grid, not visited and vacant then mark visited and push in queue
                    if(row >= 0 && row < n && col >= 0 && col < n && !visited[row][col] && grid[i][j] == 0){
                        visited[row][col] = 1;
                        q.push({row, col});
                    }
                }
            }
            level++;         
        }
        // if not possible to reach destination return -1
        return -1;
    }
};