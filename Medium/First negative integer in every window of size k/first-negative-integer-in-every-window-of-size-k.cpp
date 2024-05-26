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
                                                 
                                                 int left = 0;
                                                 int right = 0;
                                                 vector<long long> ans;
                                                 list<long long int> neg;
                                                 
                                                 while( right < N){
                                                     //calculations : store all the -ve no in list
                                                     if(A[right] < 0){
                                                         neg.push_back(A[right]);
                                                     }
                                                     
                                                     // window size == k
                                                     if(right - left + 1 == K ){
                                                         if(neg.size() == 0){
                                                             ans.push_back(0);
                                                         }
                                                         else{
                                                             ans.push_back(neg.front());
                                                             if(neg.front() == A[left]){
                                                                 neg.pop_front();
                                                             }
                                                         }
                                                         left++;
                                                     }
                                                     
                                                     right++;
                                                 }
                                                 return ans;
                                                 
                                                 
                                                 
                                                 
                                                 
 }