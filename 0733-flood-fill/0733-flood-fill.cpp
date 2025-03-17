class Solution {
public:
    int n,m;
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int initialColor, int newColor, vector<vector<int>> &ans){
        // out of bound, blocked, visited
        if(sr < 0 || sr >= n || sc < 0 || sc >= m || ans[sr][sc] != initialColor || ans[sr][sc] == newColor)
            return;
        
        ans[sr][sc] = newColor;
        for(auto dir: directions){
            int row = sr + dir.first;
            int col = sc + dir.second;

            dfs(image, row, col, initialColor, newColor, ans);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        n = image.size();
        m = image[0].size();
        vector<vector<int>> ans = image;
        int initialColor = image[sr][sc];
        dfs(image, sr, sc, initialColor, color, ans);
        return ans;
        
    }
};