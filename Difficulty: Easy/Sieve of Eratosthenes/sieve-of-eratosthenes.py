#User function Template for python3

class Solution:
    def sieveOfEratosthenes(self, N):
    	#code here 
    	prime = [1] * (N+1);
    	
    	i = 2
    	while i * i <= N:
    	    if prime[i] == 1:
    	        j = i * i
    	        while j <= N:
    	            prime[j] = 0
    	            j += i
    	    i += 1
    	
    	ans = []
    	for i in range(2, N + 1):
    	    if prime[i] == 1:
    	       ans.append(i)

        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.sieveOfEratosthenes(N)
        for i in ans:
            print(i, end=" ")
        print()
        print("~")
# } Driver Code Ends