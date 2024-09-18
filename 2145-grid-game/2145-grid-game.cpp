class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        long long top = 0, bottom = 0, ans = LONG_MAX;

        // calculate prefix sum of first row
        for(int j = 0; j < grid[0].size(); j++)
            top += grid[0][j];

        // first robot can change its direction at each col
        // so calculate how to minimise points to be collected by second robot
        for(int j = 0; j < grid[0].size(); j++){
            // points left for second robot in top row
            top -= grid[0][j];
            // minimize the second robot points
            ans = min(ans, max(top, bottom));
            // points left for second robot in last row
            bottom +=  grid[1][j];
        }
        return ans;
    }
};