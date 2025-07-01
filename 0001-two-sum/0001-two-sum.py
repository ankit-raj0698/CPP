class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lookup = {}

        for ind, ele in enumerate(nums):
            rem = target - ele
            if rem in lookup:
                return [lookup[rem], ind]
            
            lookup[ele] = ind
        
        return []
        