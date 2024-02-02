//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string str) {
        // Code here.
        int n=str.length();
        int ans=0;
        int j=0;
        for(int i=n-1;i>=0;i--){
            //if we don't subrtract '0' 
            //we will get ascii value of the character at the index
            int lastChar=str[i]-'0';
            ans+=pow(2,j)*lastChar;
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends