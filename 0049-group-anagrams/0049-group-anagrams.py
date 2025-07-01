class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        mp = defaultdict(list)
        for str in strs:
            key = "".join(sorted(str))
            mp[key].append(str)
        
        for val in mp.values():
            ans.append(val)
        
        return ans
        
        