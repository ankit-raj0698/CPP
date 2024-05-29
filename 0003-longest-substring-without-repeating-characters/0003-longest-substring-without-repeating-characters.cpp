class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxLen = 0;
        unordered_map<char,int> mp;
        while(right < s.size()){
            mp[s[right]]++;
            
            //all unique char in the current window
            if(mp.size() == right - left + 1){
                maxLen = max(maxLen, right - left +1);
            }
            // when there are duplicate char in current window so slide the window
            else if(mp.size() < right - left + 1){
                while(left <= right && mp.size() < right - left + 1){
                    mp[s[left]]--;
                    if(mp[s[left]] == 0){
                        mp.erase(s[left]);
                    }
                    left++;
                }
            }
            right++;
        }
        return maxLen;
    }
    
    
    
    
    
    /*
    sliding window left and right = 0
    use an unordered set to track unique elements seen till now
    iterate till right reaches the last index of input string
    if char "s[right]" is already in the set so shrink the window size from left
    so delete the char at s[left] from set and increment left pointer
    otherwise insert the current char s[right] in the set
    increment the right pointer everytime   
    */
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> charSet;
//         int left = 0,right = 0;
//         int maxLength = 0;
        
//         while(right<s.size()){
//             //char "s[right]" is already in the set so shrink the window size from left
//             while(charSet.find(s[right]) != charSet.end()){
//                 charSet.erase(s[left]);
//                 left++;
//             }
//             // when char is not in set so insert in the set
//             charSet.insert(s[right]);
//             maxLength = max(maxLength,right - left + 1);
//             right++;
//         }
//         return maxLength;
//     }
};