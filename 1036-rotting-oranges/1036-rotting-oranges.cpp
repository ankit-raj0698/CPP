class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        queue<pair<int,int>> q;
        vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        // Missed this edge case
        if(fresh == 0)
            return 0;

        int level = -1;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [i,j] = q.front();
                q.pop();

                for(auto dir: directions){
                    int row = i + dir.first;
                    int col = j + dir.second;

                    if(row >= 0 && row < n && col >= 0 && col < m &&
                        grid[row][col] == 1){
                            grid[row][col] = 2;
                            q.push({row,col});
                            fresh--;
                        }
                }
            }
            level++;
        }

        return fresh == 0 ? level : -1;
        
    }
};