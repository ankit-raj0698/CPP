class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        int n = strs.size();

        for(int i = 0; i < n; i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }

        for(auto itr: mp){
            ans.push_back(itr.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};