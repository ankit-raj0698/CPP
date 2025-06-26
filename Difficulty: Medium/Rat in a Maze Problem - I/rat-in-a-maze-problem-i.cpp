class Solution {
  public:
    int n;
    vector<vector<int>> visited;
    void solve(vector<vector<int>>& maze, int i, int j, string &path, vector<string> &ans){
        if(i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0 || visited[i][j])
            return;
        
        if(i == n - 1 && j == n - 1){
            ans.push_back(path);
            return;
        }
        
        visited[i][j] = 1;
        
        // up
        path.push_back('U');
        solve(maze, i - 1, j , path, ans);
        path.pop_back();
        
        // down
        path.push_back('D');
        solve(maze, i + 1, j, path, ans);
        path.pop_back();
        
        // left
        path.push_back('L');
        solve(maze, i, j - 1, path, ans);
        path.pop_back();
        
        // right
        path.push_back('R');
        solve(maze, i, j + 1, path, ans);
        path.pop_back();
        
        visited[i][j] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n = maze.size();
        visited.resize(n, vector<int>(n,0));
        vector<string> ans;
        string path="";
        solve(maze, 0, 0, path, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};