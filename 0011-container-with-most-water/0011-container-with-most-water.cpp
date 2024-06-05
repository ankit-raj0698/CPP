class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxArea = INT_MIN;
        
        while(i < j){
            // area = length  * breadth
            int area = (j - i) * min(height[i],height[j]);
            maxArea = max(maxArea, area);
            //Always move the pointer that points to the lower line
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};