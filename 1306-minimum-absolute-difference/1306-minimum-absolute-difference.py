class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        n = len(arr)
        if n < 2:
            return []
        
        arr.sort()
        mini = float("inf")

        for i in range(n-1):
            diff = abs(arr[i] - arr[i+1])
            mini = min(mini, diff)
        
        ans = []
        for i in range(n-1):
            if abs(arr[i] - arr[i+1]) == mini:
                ans.append([arr[i], arr[i+1]])
        
        return ans
        