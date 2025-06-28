class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = list(range(1,n+1))
        fact = 1
        for i in range(1,n):
            fact *= i
        
        k -= 1
        ans = ""

        while True:
            ans += str(nums[k//fact])
            nums.pop(k//fact)

            if len(nums) == 0:
                break
            
            k = k % fact
            fact = fact // len(nums)
        

        return ans
        