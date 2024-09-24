class Solution {
public:

    int n, m;

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& visited, int prev){
        // out of bound, visited, blocked
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || heights[i][j] < prev)
            return;
        // mark the current cell visited
        visited[i][j] = 1;

        // traverse all possible direction
        dfs(heights, i + 1, j, visited, heights[i][j]);
        dfs(heights, i - 1, j, visited, heights[i][j]);
        dfs(heights, i, j + 1, visited, heights[i][j]);
        dfs(heights, i, j - 1, visited, heights[i][j]);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> ans;
        if(n == 1 && m == 1){
            ans.push_back({0,0});
            return ans;
        }
            
        // create two visited array to track pacific and atlantic ocean
        vector<vector<int>> pacific(n, vector<int>(m,0));
        vector<vector<int>> atlantic(n, vector<int>(m,0));

        // do dfs for first row and first col
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || j == 0 ) && !pacific[i][j])
                    dfs(heights, i, j, pacific, -1);
            }
                
        }

        // do dfs for last row and last col
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == n - 1 || j == m - 1 ) && !atlantic[i][j])
                    dfs(heights, i, j, atlantic, -1);
            }              
        }

        // intesection of pacific and atlantic visited array
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;       
    }
};