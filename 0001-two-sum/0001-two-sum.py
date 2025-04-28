class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        j = 0
        while j < len(nums):
            rem = target - nums[j]
            if rem in mp:
                return [mp[rem], j]
            mp[nums[j]] = j
            j += 1

        return []

        