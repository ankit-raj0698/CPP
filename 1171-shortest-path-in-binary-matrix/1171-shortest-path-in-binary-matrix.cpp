class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        typedef pair<int,int> t;
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        vector<t> direction = {{0,1}, {0,-1}, {1,0}, {-1,0},
                                {1,1}, {1,-1}, {-1,1}, {-1,-1}};
            
        queue<t> q;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        q.push({0,0});
        visited[0][0] = 1;

        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [i, j] = q.front();
                q.pop();

                if(i == n-1 && j == n-1)
                    return level;
                
                for(auto dir: direction){
                    int row = i + dir.first;
                    int col = j + dir.second;

                    if(row >= 0 && row < n && col >= 0 && col < n && !visited[row][col] && grid[row][col] == 0){
                        q.push({row, col});
                        visited[row][col] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};