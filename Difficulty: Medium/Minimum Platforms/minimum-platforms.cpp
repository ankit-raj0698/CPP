//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            int start = arr[i];
            int end = dep[i];
            
            mp[start]++;
            mp[end + 1]--;
        }
        
        int sum = 0;
        int maxi = 0;
        for(auto it: mp){
            sum += it.second;
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.
//  Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends