//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	    void solve(string s, int index, string temp, vector<string> &ans){
	        if(index >= s.size()){
	            if(!temp.empty()){
	                ans.push_back(temp);
	            }
	            return;
	        }
	        
	        //include
	        temp.push_back(s[index]);
	        solve(s,index+1,temp,ans);
	        
	        //exclude
	        temp.pop_back();
	        solve(s,index+1,temp,ans);
	        
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string temp = "";
		    solve(s,0,temp,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends