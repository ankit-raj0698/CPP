//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    bool check(vector<int> &stalls, int k, int mid){
        int cowcnt = 1;
        int lastpos = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - lastpos >= mid){
                cowcnt++;
                if(cowcnt == k)
                    return true;
                lastpos = stalls[i];
            }
        }
        
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n = stalls.size();
        int mini = 1e9, maxi = -1e9;
        for(int ele: stalls){
            mini = min(mini, ele);
            maxi = max(maxi, ele);
        }
        
        sort(stalls.begin(), stalls.end());
        
        int low = 0, high = maxi - mini;
        int ans = low;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(check(stalls, k, mid)){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends