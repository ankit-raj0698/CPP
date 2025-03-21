class Solution {
public:
    vector<int> prevSmaller(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> res;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()]  >= heights[i])
                st.pop();
            
            if(st.empty())
                res.push_back(-1);
            else
                res.push_back(st.top());
            
            st.push(i);
        }

        return res;
    }


    vector<int> nextSmaller(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> res;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                res.push_back(n);
            else
                res.push_back(st.top());
            
            st.push(i);
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {

        int maxArea = 0;

        vector<int> left = prevSmaller(heights);
        vector<int> right = nextSmaller(heights);


        for(int i = 0; i < heights.size(); i++){
            
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m);

        for(int j = 0; j < m; j++)
                heights[j] = matrix[0][j] - '0';

        int maxArea = largestRectangleArea(heights);;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j] = heights[j] + matrix[i][j] - '0';
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

};