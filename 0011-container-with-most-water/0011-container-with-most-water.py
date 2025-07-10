class Solution:
    def maxArea(self, height: List[int]) -> int:
        res, maxWater = 0,0
        left , right = 0, len(height) - 1

        while left < right:
            width = right - left
            ht = min(height[left], height[right])

            res = width * ht
            maxWater = max(maxWater, res)

            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1
        
        return maxWater
        