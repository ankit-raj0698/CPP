class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        my_dict = {}
        result = []

        for l in nums1:
            key = l[0]
            value = l[1]
            my_dict[key] = value
        
        for l in nums2:
            key = l[0]
            value = l[1]
            if key in my_dict:
                my_dict[key] = value + my_dict[key]
            else:
                my_dict[key] = value
        
        for key,value in my_dict.items():
            temp = []
            temp.append(key)
            temp.append(value)
            result.append(temp)
        
        result.sort()
        # print(result)

        return result
        