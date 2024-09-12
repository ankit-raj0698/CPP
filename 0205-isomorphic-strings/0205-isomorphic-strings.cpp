class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char,char> mpst;
        unordered_map<char, char> mpts;

        for(int i = 0; i < s.size(); i++){

            char c1 = s[i];
            char c2 = t[i];

            // If a mapping exists but doesn't match
            if (mpst.count(c1) && mpst[c1] != c2)
                return false;
            if (mpts.count(c2) && mpts[c2] != c1)
                return false;

            // Create the mapping if it doesn't exist
            mpst[c1] = c2;
            mpts[c2] = c1;
        }
        return true;
    }
};