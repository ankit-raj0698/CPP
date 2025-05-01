class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = Counter(nums)
        heap = []

        for ele, freq in mp.items():
            heapq.heappush(heap, (freq, ele))

            if len(heap) > k:
                heapq.heappop(heap)
        
        ans = []
        for freq, ele in heap:
            ans.append(ele)
        
        return ans
        