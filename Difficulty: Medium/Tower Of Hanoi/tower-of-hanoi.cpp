//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // You need to complete this function
    int power(int x, int n){
        if(n == 0)
            return 1;
        long long half = power(x, n/2);
        if(n % 2 == 0)
            return half * half;
        return x * half * half;
    }

    int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        if(n == 0)
            return 0;
        
        return power(2,n) - 1;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T; // testcases
    while (T--) {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.towerOfHanoi(N, 1, 3, 2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends