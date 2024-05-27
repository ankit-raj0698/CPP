//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int k = pat.size();
	    unordered_map<char,int> mp;
	    // count freq of each element in pattern
	    for(char c: pat){
	        mp[c]++;
	    }
	    
	    int cnt = mp.size();
	    int ans = 0;
	    int left = 0, right = 0;
	    
	    while(right < txt.size()){
	        //calculations
	        if(mp.count(txt[right])){
	            mp[txt[right]]--;
	            if(mp[txt[right]] == 0){
	                cnt--;
	            }
	        }
	        
	        // windowsize == k
	        if(right - left + 1 == k){
	            //calculate the ans
	            if(cnt == 0){
	                ans++;
	            }
	            
	            //slide the window
	            if(mp.count(txt[left])){
	                 mp[txt[left]]++;
	                 if(mp[txt[left]] == 1){
	                     cnt++;
	                }
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
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends