class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int length = 0;
        
        for(int right =0; right<s.size();right++){
            //char "s[right]" is already in the set so shrink the window size from left
            while(charSet.find(s[right]) != charSet.end()){
                charSet.erase(s[left]);
                left++;
            }
            // when char is not in set so insert in the set
            charSet.insert(s[right]);
            length = max(length,right - left + 1);
        }
        return length;
    }
};