class Solution {
public:
    int partitionString(string s) {
        int res = 0;
        unordered_set<char> myset;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(myset.find(ch) != myset.end()){
                res++;
                myset.clear();
            }

            myset.insert(ch);
        }
        return res + 1;
    }
};