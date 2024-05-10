class Solution {
public:
    /*
    create a vector<vector<string>> to store answer
    create a map (key -> string, value -> vector<string>)
    iterate through each element of input string
    store the sorted version of current element as key and push_back unsorted version of         current element as value in map
    iterate through the map to store the values of map(vector<string>) in answer
    return ans  
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        
        for(auto str:strs){
            string key=str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }       
        for(auto ele:mp){
            ans.push_back(ele.second);
        }      
        return ans;           
    }
};