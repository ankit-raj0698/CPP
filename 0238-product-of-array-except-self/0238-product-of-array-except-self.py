class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [1] * n
        right = [1] * n

        for i in range(1,n):
            left[i] = left[i-1] * nums[i-1]
        
        
        ans = [1] * n
        prod = 1
        for i in range(n-1, -1, -1):
            ans[i] = left[i] * prod
            prod *= nums[i]
        
        return ans
        