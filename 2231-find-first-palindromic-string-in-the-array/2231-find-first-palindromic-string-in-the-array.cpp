class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {

        string res = "";

        for(string str: words){
            if(isPalindrome(str, 0, str.size()-1)){
                res = str;
                break;
            }
        }
        return res;
    }
};