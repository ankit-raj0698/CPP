class Solution {
public:
    int n;
    
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void solve(string s, int ind, vector<string> &temp, vector<vector<string>> &ans){
        
        if(ind >= s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(s,ind,i)){
                // push the substring from ind to i as we have partitioned till i
                temp.push_back(s.substr(ind, i - ind + 1));
                solve(s, i + 1 , temp, ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        n = s.size();
        vector<vector<string>> ans;
        vector<string> temp ;
        
        solve(s, 0, temp, ans);
        return ans;
        
        
    }
};