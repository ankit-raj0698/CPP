class Solution {
public:
    bool makeEqual(vector<string>& words) {

        unordered_map<char, int> count;
        int n = words.size();
        for(int i = 0; i < words.size(); i++){
            string str = words[i];
            for(int j = 0; j < str.length(); j++)
                count[str[j]]++;
        }

        for(auto &[key,val] : count){
            if(val % n != 0)
                return false;
        }
        return true;
    }
};