class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ans = []
        pq = []
        freq = Counter(nums)
        for key,val in freq.items():
            heapq.heappush(pq,(val,key))

            if len(pq) > k:
                heapq.heappop(pq)
        
        for count,key in pq:
            ans.append(key)
        
        return ans


        