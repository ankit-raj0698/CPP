class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ans = []
        pq = []
        freq = Counter(nums)
        for num,count in freq.items():

            heapq.heappush(pq,(count,num))

            if len(pq) > k:
                heapq.heappop(pq)
        
        for count,num in pq:
            ans.append(num)
        
        return ans


        