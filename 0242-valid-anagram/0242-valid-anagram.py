class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        cnt1 = Counter(s)
        cnt2 = Counter(t)

        return cnt1 == cnt2
        