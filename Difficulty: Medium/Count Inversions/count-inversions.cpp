//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
    int cnt = 0;
    void merge(vector<int> &arr, int l, int r){
        int mid = l + (r - l)/2;
        int n = mid - l + 1;
        int m = r - mid;
        
        vector<int> left(n);
        vector<int> right(m);
        
        int k = l;
        for(int i = 0; i<n; i++)
            left[i] = arr[k++];
        
        k = mid + 1;
        for(int i = 0; i < m; i++)
            right[i] = arr[k++];
        
        
        int i = 0, j = 0;
        k = l;
        while(i < n && j < m){
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else{
                // left > right
                arr[k++] = right[j++];
                cnt += (n-i);
            }
                
        }
        
        while(i < n)
            arr[k++] = left[i++];
        
        while(j < m)
            arr[k++] = right[j++];
    }
    
    void mergesort(vector<int> &arr, int l, int r){
        if(l >= r)
            return;
        
        int mid = l + (r - l)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, r);
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        mergesort(arr, 0, n-1);
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends