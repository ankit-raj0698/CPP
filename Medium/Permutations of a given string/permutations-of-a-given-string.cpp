//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void solve(string s,int index,vector<string> &ans){
            if(index >= s.size()){
                int cnt = count(ans.begin(), ans.end(), s);
                if(cnt > 0){
                    return;
                }
                ans.push_back(s);
                return;
            }
            
            for(int i=index;i<s.size();i++){
                swap(s[i],s[index]);
                solve(s,index+1,ans);
            }
        }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    int index=0;
		    solve(S,index,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends