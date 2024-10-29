//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int n;
    bool isPossible(vector<int> &stalls, int k, int mid){
        int cowCount = 1;
        int lastPos = stalls[0];
        for(int i = 0; i < n; i++){
            if(stalls[i] - lastPos >= mid){
                cowCount++;
                if(cowCount == k)
                    return true;
                lastPos = stalls[i];
            }
        }
        return false;
    }

    int aggresiveCows(vector<int> &stalls, int k) {

        // Write your code here
        n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int maxi = *max_element(stalls.begin(), stalls.end());
        int mini = *min_element(stalls.begin(), stalls.end());
        
        int start = 0;
        int end = maxi - mini;
        int ans = -1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(isPossible(stalls, k, mid)){
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
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
        int ans = ob.aggresiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends