class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans(n, vector<int>(m));
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                     ans[i][j] = matrix[i][j] == '0' ? 0 : 1;
                     maxi = max(maxi, ans[i][j]);
                }
            }
        }

        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == '0')
                    ans[i][j] = 0;
                else{
                    ans[i][j] = min({ans[i][j-1], ans[i-1][j], ans[i-1][j-1]}) + 1;
                    maxi = max(maxi, ans[i][j]);
                }
            }
        }
        return maxi * maxi;
        
    }
};