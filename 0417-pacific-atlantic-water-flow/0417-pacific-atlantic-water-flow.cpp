class Solution {
public:
    int n, m;
    vector<pair<int, int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>> &visited, int prevHeight){
        // out of bound, visited, blocked
        // path is blocked when current cell height is less than prev height
        // as we are checking from one ocean to another and not from any cell
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || heights[i][j] < prevHeight)
            return;
        
        visited[i][j] = 1;

        for(auto dir: direction){
            int row = i + dir.first;
            int col = j + dir.second;

            dfs(heights, row, col, visited, heights[i][j]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m,0));
        vector<vector<int>> atlantic(n, vector<int>(m,0));

        // check if you can reach from pacific to atlantic
        // check for first row and col
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || j == 0) && !pacific[i][j])
                    dfs(heights, i, j, pacific, -1);
            }
        }

        // check if you can reach from atlantic to pacific
        // check for last row and col
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == n - 1 || j == m - 1) && !atlantic[i][j])
                    dfs(heights, i, j, atlantic, -1);
            }
        }

        // find the intersection of both the visited array
       vector<vector<int>> ans;
       for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(atlantic[i][j] && pacific[i][j])
                    ans.push_back({i,j});
            }
        } 
        return ans;
    }
};