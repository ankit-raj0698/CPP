class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str: strs){
            string newstr = str;
            sort(newstr.begin(), newstr.end());
            string key = newstr;
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};