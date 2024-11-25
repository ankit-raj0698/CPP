//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(vector<vector<int>> &matrix, int R, int C, int mid){
        // find no. elements smaller than equal to mid in each matrix row
        int cnt = 0;
        for(int i = 0; i < R; i++){
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        int req = (R*C)/2;
        if(cnt > req)
            return true;
        return false;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here      
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < R; i++){
            mini = min(mini, matrix[i][0]);
            maxi = max(maxi, matrix[i][C-1]);
        }
        
        int low = mini, high = maxi;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(matrix, R, C, mid)){
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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends