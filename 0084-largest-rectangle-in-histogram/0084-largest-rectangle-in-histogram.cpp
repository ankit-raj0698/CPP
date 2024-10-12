class Solution {
public:
    vector<int> prevSmaller(vector<int>& heights, int n){
        stack<int> s;
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& heights, int n){
        stack<int> s;
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = prevSmaller(heights, n);
        vector<int> right = nextSmaller(heights, n);
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            // area = width * height
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};