class Solution {
public:

    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--])
                return false;
        }
        return true;
    }
    int minimumLength(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right){
        
            if(s[left] == s[right]){
                while(left < right && s[left] == s[left + 1])
                    left++;
                
                while(left < right && s[right] == s[right - 1])
                    right--;
                
                left++;
                right--;
            }
            else
                break;
        }
        
        // right will only be less than left when it is palindromic string
        // and we have seen all char so return 0
        return right < left ? 0 : right - left + 1;
    }
};