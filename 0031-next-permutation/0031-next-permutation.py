class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # find the index of element such that nums[i] < nums[i+1]
        i = len(nums) - 2
        index = -1
        while i >= 0:
            if nums[i] < nums[i + 1]:
                index = i
                break
            i -= 1
        

        if index != -1:
            j = len(nums) - 1
            # find the index of element which is greater than nums[index]
            while nums[j] <= nums[index]:
                j -= 1
            # swap nums[j] and nums[index]
            nums[j], nums[index] = nums[index], nums[j]
            
        # reverse the part after index + 1
        nums[index+1:] = reversed(nums[index+1:])