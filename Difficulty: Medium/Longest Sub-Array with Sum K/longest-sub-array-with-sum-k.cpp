//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int> mp;
        int prefixsum = 0;
        int maxLen =  0;
        for(int i = 0; i < N; i++){
            prefixsum += A[i];
            
            if(prefixsum == K)
                maxLen = i+1;
                
            else if(mp.find(prefixsum - K) != mp.end())
                maxLen = max(maxLen, i - mp[prefixsum - K]);
            
            if(mp.find(prefixsum) == mp.end())
                mp[prefixsum] = i;
                
        }
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends