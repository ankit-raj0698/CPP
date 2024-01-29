//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    long long int left=0,right=0;
    list<long long> temp;
    vector<long long> ans;
    
    while(right<N){
        if(A[right]<0){
            temp.push_back(A[right]);
        }
        if(right-left+1 == K){
            if(temp.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(temp.front());
                if(A[left]==temp.front()){
                    temp.pop_front();
                }
            }
            left++;
        }
        right++;
    }
                                                 
    return ans;                                             
 }