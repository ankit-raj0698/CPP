class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
            
        nums.sort()
        print(nums)
        curlen,maxlen = 1,1

        for i in range(len(nums) - 1):
            if nums[i] == nums[i+1]:
                continue
            elif nums[i] == nums[i+1] - 1:
                curlen += 1
            else:
                curlen = 1
            maxlen = max(maxlen, curlen)
        
        return maxlen
        