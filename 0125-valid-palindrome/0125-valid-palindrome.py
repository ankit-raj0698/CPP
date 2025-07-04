class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1

        while left < right:
            while left < right and (s[left].isalnum()  == False or s[left].isspace()):
                left += 1
            while left < right and (s[right].isalnum() == False or s[right].isspace()):
                right -= 1
            
            if s[left].lower() != s[right].lower():
                return False
            else:
                left += 1
                right -= 1
        return True
        