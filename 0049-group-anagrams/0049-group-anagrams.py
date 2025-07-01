class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        mp = defaultdict(list)
        for str in strs:
            # key = "".join(sorted(str))
            # mp[key].append(str)
            count = [0] * 26
            for ch in str:
                count[ord(ch) - ord('a')] += 1
            
            mp[tuple(count)].append(str)
        
        # for val in mp.values():
        #     ans.append(val)
        
        # return ans

        return list(mp.values())
        
        