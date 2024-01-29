//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int windowLeft=0,windowRight=0;
	    int ans=0;
	    
	    //create two vectors to count frequency of each character
	    vector<int> patArr(26,0);
	    vector<int> txtArr(26,0);
	    
	    //Size of window will be equal to length of pattern
	    int K=pat.length();
	    
	    //Find frequency of each character in pattern
	    for(char c:pat){
	        patArr[c-'a']++;
	    }
	    
	    //loop until right of window reaches end of text
	    while(windowRight < txt.length()){
	        
	        //count the frequency of character of text
	        txtArr[ txt[windowRight] - 'a' ]++;
	        
	        //when window length is equal to K
	        if(windowRight - windowLeft + 1 == K){
	            
	            //when count of characters of pattern = count of characters of text in current window
	            if(patArr==txtArr){
	                ans++;
	            }
	            
	            //slide the window by removing the character present at windowLeft of text string in txtArr
	            txtArr[txt[windowLeft]-'a']--;
	            windowLeft++;
	            
	        }
	        
	       windowRight++; 
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