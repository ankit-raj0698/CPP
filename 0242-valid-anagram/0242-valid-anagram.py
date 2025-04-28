class Solution:
    '''
        cnt1 = Counter(s)
        cnt2 = Counter(t)
        return cnt1 == cnt2 
    '''
    def isAnagram(self, s: str, t: str) -> bool:
        mp = dict()

        for c in s:
            if c in mp:
                mp[c] += 1
            else: 
                mp[c] = 1
        
        print(mp)
        
        for c in t:
            if c in mp:
                mp[c] -= 1
            else:
                return False
        
        print(mp)
        
        for c in mp:
            if mp[c] == 0:
                continue
            else:
                return False
        
        return True
            
        
        