class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int ans = 0;
        while(left < right){
            int length = Math.min(height[left], height[right]);
            int width = right - left;
            ans = Math.max(ans, length * width);
            if(height[left] < height[right])
                left++;
            else 
                right--;
        }
        return ans;
    }
}