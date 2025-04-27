class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mp = defaultdict(int)
        for x in nums:
            if x in mp:
                return True
            mp[x] += 1
        
        return False
        