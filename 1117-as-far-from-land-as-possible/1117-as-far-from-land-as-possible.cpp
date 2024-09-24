class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        queue<pair<int, int>> q;

        // Push all land cells (1s) into the queue and mark them visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        // If there are no land cells or no water cells, return -1
        if (q.empty() || q.size() == n * n) return -1;

        int level = -1; // because we are popping out all the 1's in first level
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();

                // Check all four directions
                for (auto dir : direction) {
                    int row = i + dir.first;
                    int col = j + dir.second;

                    // Check if the neighboring cell is within bounds and not visited
                    if (row >= 0 && col >= 0 && row < n && col < n && !visited[row][col]) {
                        visited[row][col] = 1;
                        q.push({row, col});
                    }
                }
            }
            level++;
        }

        return level;
    }
};
