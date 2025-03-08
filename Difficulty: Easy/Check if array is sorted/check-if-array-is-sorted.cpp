//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool solve(vector<int> &arr, int i){
        if(i == 0)
            return true;
        if(arr[i] < arr[i-1])
            return false;
        
        return solve(arr, i - 1);
    }
    bool arraySortedOrNot(vector<int>& arr) {
        // code here
        int n = arr.size();
        return solve(arr, n-1);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(nums);
        cout << (ans ? "true" : "false") << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends