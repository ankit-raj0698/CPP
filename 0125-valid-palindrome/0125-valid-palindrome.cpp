class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(isalnum(ch)){
                if(isalpha(ch)){
                    newStr += tolower(ch);
                }
                else{
                    newStr += ch;
                }                
            }
        }
        int i=0;
        int j=newStr.size()-1;
        
        while(i<=j){
            if(newStr[i] != newStr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};