class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramGroup;
        int n = strs.size();

        for(int i = 0; i < n; i++){
            string sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            anagramGroup[sortedWord].push_back(strs[i]);
        }

        for(auto group: anagramGroup){
            result.push_back(group.second);
        }
        sort(result.begin(), result.end());
        return result;
        
    }
};