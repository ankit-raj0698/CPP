class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
       
        queue<pair<int,int>> q;
        vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> grid = mat;
        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
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

                for(auto dir: directions){
                    int row = i + dir.first;
                    int col = j + dir.second;

                    if(row >= 0 && row < n && col >= 0 && col < m &&
                        mat[row][col] == 1 && !visited[row][col]){
                            grid[row][col] = level + 1;
                            visited[row][col] = 1;
                            q.push({row,col});
                        }
                }
            }
            level++;
        }
        return grid;
    }
};