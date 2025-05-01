class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        n = len(nums)
        if n == 0:
            return 0

        nums.sort()

        cnt = 1
        ans = 1

        for i in range(0, len(nums) - 1):
            if nums[i] == nums[i+1]:
                continue
            elif nums[i] + 1 == nums[i + 1]:
                cnt += 1
                ans = max(cnt, ans)
            else:
                cnt = 1
        
        return ans
        



        