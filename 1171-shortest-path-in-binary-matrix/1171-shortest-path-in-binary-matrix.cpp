class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        queue<pair<int,int>> q;
        vector<pair<int,int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        q.push({0,0});
        visited[0][0] = 1;

        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [i,j] = q.front();
                q.pop();

                if(i == n-1 && j == n-1)
                    return level;
                
                for(auto dir: direction){
                    int row = i + dir.first;
                    int col = j + dir.second;

                    if(row >= 0 && row < n && col >= 0 && col < n && !visited[row][col] && grid[row][col] == 0){
                        visited[row][col] = 1;
                        q.push({row, col});
                    }
                }

            }
            level++;
        }
        return -1;
    }
};