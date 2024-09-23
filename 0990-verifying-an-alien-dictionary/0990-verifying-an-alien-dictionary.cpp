class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        // store index of each char of order in map
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i + 1];

            int n = min(w1.size(), w2.size());
            for(int j = 0; j < n; j++){
                char c1 = w1[j];
                char c2 = w2[j];
               
                if(mp[c1] < mp[c2])
                    break;
                else if(mp[c1] > mp[c2])
                    return false;
                
                // all char of w1 is same as w2 till now but len of w2 is smaller
                // so w2 should come first
                if(j == n - 1 && w1.size() > w2.size())
                    return false;
                
            }
        }
       return true; 
    }
};