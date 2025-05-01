class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for str in strs:
            key = ''.join(sorted(str))
            mp[key].append(str)
        

        return list(mp.values())
        