class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mydict = defaultdict(list)

        for str in strs:
            key = ''.join(sorted(str))
            mydict[key].append(str)
        
        return list(mydict.values())
        