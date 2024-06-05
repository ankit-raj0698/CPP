class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxArea = INT_MIN;
        
        while(i < j){
            // area = length  * breadth
            int area = (j - i) * min(height[i],height[j]);
            maxArea = max(maxArea, area);
            //whichever index is at smaller height, update it
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};