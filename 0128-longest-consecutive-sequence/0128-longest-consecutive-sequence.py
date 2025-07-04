class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        lookup = set(nums)
        curlen, maxlen = 1, 1

        for ele in lookup:
            if ele - 1 in lookup:
                continue
            
            while ele + 1 in lookup:
                curlen += 1
                maxlen = max(maxlen, curlen)
                ele += 1
            
            curlen = 1
        
        return maxlen
        