#User function Template for python3

class Solution:
    def largestPrimeFactor (self, N):
        # code here
        ans = -1
        i = 2
        while i * i <= N:
            if N % i == 0:
                ans = i
                while N % i == 0:
                    N = N // i
            i += 1
        if N != 1:
            return N
        return ans
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
       

        ob = Solution()
        print(ob.largestPrimeFactor(N))
        print("~")
# } Driver Code Ends