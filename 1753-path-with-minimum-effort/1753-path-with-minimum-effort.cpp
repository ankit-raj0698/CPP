class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Type alias for priority queue elements: {effort, {i, j}}
        typedef pair<int, pair<int, int>> t; 

        // Result matrix to track the minimum effort to reach each cell
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        // Possible directions of movement: right, left, down, up
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Priority queue (min-heap) to explore cells based on minimum effort 
        // {maxdiff, {i, j}}
        priority_queue<t, vector<t>, greater<t>> pq;

        // Start from the top-left corner (0,0) with 0 effort
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();

            // Current cell's effort and coordinates
            int diff = front.first;
            int i = front.second.first;
            int j = front.second.second;

            // Explore all 4 possible directions
            for (auto dir : direction) {
                int row = i + dir.first;
                int col = j + dir.second;

                // Check if the new cell is within bounds
                if (row >= 0 && row < n && col >= 0 && col < m) {
                    // Calculate the absolute height difference between the current cell and the next one
                    int absDiff = abs(heights[i][j] - heights[row][col]);
                    // Calculate the maximum difference along the current path
                    int maxDiff = max(diff, absDiff);

                    // If the new path provides a smaller maximum effort, update and push it into the queue
                    if (maxDiff < result[row][col]) {
                        result[row][col] = maxDiff;
                        pq.push({maxDiff, {row, col}});
                    }
                }
            }
        }

        // Return the minimum effort to reach the bottom-right corner (n-1, m-1)
        return result[n-1][m-1];
    }
};
