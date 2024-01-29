//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int left=0,right=0;
        
        //using a list to keep track of max element
        list<int> maxList;
        vector <int> ans;
        
        while(right<n){
            
            //Calculation
            //Remove all the element which is lower than current element from maxlist
            //elements left to max is of no use so remove them 
            //as when we are sliding the window they have to be deleted
            // element right to max may be useful to push them to maxList 
            
            while(!maxList.empty() && maxList.back() < arr[right]){
                maxList.pop_back();
            }
            //2nd,3rd....largest element may be useful for our calculation
            maxList.push_back(arr[right]);
            
            if(right-left+1 == k){
                //Store  ans
                ans.push_back(maxList.front());
                
                //Slide the window
                if(arr[left]==maxList.front()){
                    maxList.pop_front();
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends