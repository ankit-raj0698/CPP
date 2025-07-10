class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxWater = 0
        left , right = 0, len(height) - 1

        while left < right:
            width = right - left
            ht = min(height[left], height[right])
            
            maxWater = max(maxWater, width * ht)

            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1
        
        return maxWater
        