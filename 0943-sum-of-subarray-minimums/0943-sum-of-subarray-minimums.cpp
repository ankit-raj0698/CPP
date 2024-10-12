class Solution {
public:
    vector<int> nextSmaller(vector<int> &arr, int n){
        stack<int> s;
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            ans[i] = s.empty() ? n : s.top();
            //push index to the stack
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &arr, int n){
        stack<int> s;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            
            ans[i] = s.empty() ? -1 : s.top();
            //push index to the stack
            s.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> left = prevSmaller(arr, n);
        vector<int> right = nextSmaller(arr, n);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += (long long)(i - left[i]) * (right[i] - i) * arr[i] % mod;
        }

        return sum % mod;
        
    }
};