class Solution {
public:
    // we will use two simultaneous dfs concept 
    int n, m;
    vector<pair<int, int>> direction = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2, int i, int j, vector<vector<int>> &visited){

        //out of bound, already visited , blocked for grid2 then we have no problem
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid2[i][j] == 0)
            return true;

        visited[i][j] = 1;
        
        // when corresponding grid1 cell is 0 but grid2 cell is 1 then obviously 
        // grid2 can't be sub island but if we immediately return false then it might
        // happen other part of this grid2 component is considered as valid
        // so better is to neglect entire grid2 component fully
        bool status = true;
        if(grid1[i][j] == 0)
            status = false;
       

        for(auto dir: direction){
            int row = i + dir.first;
            int col = j + dir.second;
            status = dfs(grid1, grid2, row, col, visited) &&  status;
        }
        
        return status;
    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid2[i][j] == 1){
                    if(dfs(grid1, grid2, i, j, visited))
                        ans++;
                }
            }
        }

        return ans;
        
    }
};