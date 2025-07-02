class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        prod, prod_wo, zeroCnt = 1, 1, 0

        for num in nums:
            if num == 0:
                zeroCnt += 1
                prod = 0
            else:
                prod *= num
                prod_wo *= num
        
        if zeroCnt > 1:
            return [0] * len(nums)
        
        # ans = []
        # for num in nums:
        #     if num == 0:
        #         ans.append(prod_wo)
        #     else:
        #         ans.append(prod//num)

        # return ans

        ans = [0] * len(nums)
        for i,num in enumerate(nums):
            if num == 0:
                ans[i] = prod_wo
            else:
                ans[i] = prod//num

        return ans


        