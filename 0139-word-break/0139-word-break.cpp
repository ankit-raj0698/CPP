class Solution {
public:
    int n;
    unordered_set<string> st;
    int dp[301];

    bool solve(string &s, int ind){
        // base case : we have seen entire string 
        if(ind >= n)
            return true;
        
        // entire string is present in dict so no need of word break
        if(st.find(s) != st.end())
            return true;
        
        if(dp[ind] != -1)
            return dp[ind];

        // break the string for each length word i.e.. 1,2,3,....n
        for(int l = 1; l <= n; l++){
            string str = s.substr(ind, l);
            //if str is present in word dict, call recursion on next index
            if(st.find(str) != st.end() && solve(s, ind + l))
                return dp[ind] = true;
        }
        return dp[ind] =  false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(dp, -1, sizeof(dp));

        for(auto str: wordDict)
            st.insert(str);
        
        return solve(s, 0);
        
    }
};