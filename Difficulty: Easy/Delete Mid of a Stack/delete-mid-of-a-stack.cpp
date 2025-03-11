//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(stack<int>& s, int n, int count){
        
     if(count == (n)/2){
         s.pop();
         return;
     }
            
            
        int val = s.top();
        count++;
        s.pop();
        solve(s,n,count);
        s.push(val);   
    }
    void deleteMid(stack<int>& s) {
        // code here..
        solve(s, s.size(), 0);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        stack<int> s;
        int num;
        while (ss >> num) {
            s.push(num);
        }

        Solution ob;
        ob.deleteMid(s);
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends