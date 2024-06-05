class Solution {
public:
 
    
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0,right = 0;
        int maxLength = 0;
        
        while(right<s.size()){
            //char "s[right]" is already in the set so shrink the window size from left
            while(charSet.find(s[right]) != charSet.end()){
                charSet.erase(s[left]);
                left++;
            }
            // when char is not in set so insert in the set
            charSet.insert(s[right]);
            maxLength = max(maxLength,right - left + 1);
            right++;
        }
        return maxLength;
    }
};