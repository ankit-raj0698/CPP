//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(int i, int j, vector<vector<int>> &m,int n){
        if(i < 0 || i >=n || j < 0|| j >=n || m[i][j] == 0){
            return false;
        }
        return true;
    }
    
    void solve(int i, int j, vector<vector<int>> &m,int n, string path, vector<string> &ans){
        
        //not safe to move so return
        if(!isSafe(i,j,m,n)){
            return;
        }
        
        // reached the dest
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        
        //marking the current cell as 0 to avoid infinte loop
        m[i][j] = 0;
        
        // moves possible Left, Right, Up, Down
        
        //Left move
        path.push_back('L');
        solve(i,j-1,m,n,path,ans);
        path.pop_back();
        
        //Right move
        path.push_back('R');
        solve(i,j+1,m,n,path,ans);
        path.pop_back();
        
        //Down move
        path.push_back('D');
        solve(i+1,j,m,n,path,ans);
        path.pop_back();
        
        //UP move
        path.push_back('U');
        solve(i-1,j,m,n,path,ans);
        path.pop_back();
        
        // When function call returns, we will reset the cell value
        m[i][j] = 1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        int i = 0, j = 0;
        
        solve(i,j,m,n,path,ans);
        
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends