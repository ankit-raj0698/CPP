class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        
        #find the index of the element such that nums[i] < nums[i+1]
        i = len(nums) - 2
        index = -1
        while i >= 0:
            if nums[i] < nums[i+1]:
                index = i
                break
            i -= 1
        
        #find the index of the element which is just greater than nums[index]
        #swap it with nums[index]
        if i != -1:
            j = len(nums) - 1
            while j >= 0:
                if nums[j] > nums[index]:
                    nums[index], nums[j] = nums[j], nums[index]
                    break
                j -= 1
        
        #reverse the list from index+1 to end
        nums[index+1:] = reversed(nums[index+1:])

        