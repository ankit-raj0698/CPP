class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int ans = 0;
        while(left < right){
            int width = right - left;
            if(height[left] < height[right]){
                ans = Math.max(ans, height[left] * width);
                left++;
            }
            else{
                ans = Math.max(ans, height[right] * width);
                right--;
            }
        }
        return ans;
    }
}