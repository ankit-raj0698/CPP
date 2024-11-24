
class Solution:
    def gcd(self, a : int, b : int) -> int:
        # code here
        if a <= 0 or b <= 0:
            raise ValueError("Inputs must be positive integers.")
        
        while a > 0 and b > 0:
            if a > b:
                a = a % b
            else:
                b = b % a
        
        if a == 0:
            return b
        
        return a
        



#{ 
 # Driver Code Starts

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        a = int(input())
        
        
        b = int(input())
        
        obj = Solution()
        res = obj.gcd(a, b)
        
        print(res)
        

        print("~")
# } Driver Code Ends