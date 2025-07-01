class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
            
        cnts = defaultdict(int)

        for ch in s:
            cnts[ch] += 1
        
        for ch in t:
            if ch not in cnts:
                return False

            cnts[ch] -= 1
        
        for key, val in cnts.items():
            if val != 0:
                return False
        
        return True
        