class Solution {
public:

    int n,m;
    vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void bfs(vector<vector<int>>& land, vector<vector<int>> &visited, int i, int j, vector<int> &temp){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;

        int last_row = -1;
        int last_col = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [i,j] = q.front();
                q.pop();

                last_row = i;
                last_col = j;

                for(auto dir: directions){
                    int row = i + dir.first;
                    int col = j + dir.second;

                    if(row >= 0 && row < n && col >= 0 && col < m &&
                        land[row][col] == 1 && !visited[row][col]){
                            q.push({row, col});
                            visited[row][col] = 1;
                        }
                }
            }
        }
        temp.push_back(last_row);
        temp.push_back(last_col);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0)); 
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && land[i][j] == 1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    bfs(land, visited, i, j, temp); 
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};