//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool check(vector<int> &arr, int k, int mid){
        int stucnt = 1;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++){
            if(sum + arr[i] <= mid){
                sum += arr[i];
            }
            else{
                stucnt++;
                if(stucnt > k || arr[i] > mid)
                    return false;
                sum = arr[i];
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
       // sort(arr.begin(), arr.end());
        int low = arr[n-1], high = sum;
        
        if(k > n)
            return -1;
        
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(check(arr, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends