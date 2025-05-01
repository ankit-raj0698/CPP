class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mp = defaultdict(list)
        for str in strs:
            key = ''.join(sorted(str))
            mp[key].append(str)
        

        return list(mp.values())
        