class Solution {
public:

//  BFS Approach
    
    int n, m;
    vector<pair<int,int>> direction = {{-1,0} , {1,0}, {0,1}, {0,-1}};

    bool isSafe(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &visited){
        if(i >= 0 && j >= 0 && i < n && j < m && !visited[i][j] && grid[i][j] == '1')
            return true;
        return false;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &visited){
        queue<pair<int, int>> q;
        q.push({i,j});
        visited[i][j] = 1;

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            i = front.first;
            j = front.second;

            for(auto dir: direction){
            int row = i + dir.first;
            int col = j + dir.second;
            if(isSafe(grid, row, col, visited)){
                visited[row][col] = 1;
                q.push({row, col});
            }
        }
    }       
}
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int ans = 0;
        
        vector<vector<int>> visited(n,vector<int>(m,false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    bfs(grid, i, j, visited);
                }  
            }
        }
        return ans;
    }
        
};