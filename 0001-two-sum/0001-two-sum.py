class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}

        for ind, ele in enumerate(nums):
            rem = target - ele
            if rem in mp:
                return [mp[rem], ind]
            mp[ele] = ind
 

        return []

        