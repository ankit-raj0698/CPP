class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        
        //Sort the string
        //After sorting whatever string you got will be your key
        //and its corresponding string will be a value

        for(auto s:strs){
            string newstr=s;
            sort(newstr.begin(),newstr.end());
            m[newstr].push_back(s);
        }

        //For each key you have a vector of string
        //Push those vector to ans and return ans
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};