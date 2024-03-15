class Solution {
public:
    
    bool isValidChar(char ch){
        return isalpha(ch) || isdigit(ch);
    }
    
    bool solve(string newStr){
        int i=0,j=newStr.size()-1;
        while(i<j){
            if(newStr[i]!=newStr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        
        if(s.size()==0){
            return true;
        }
        string newStr="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isValidChar(ch)){
               newStr+= tolower(ch);
            }
        }
        //cout<<newStr<<endl;
        
        return solve(newStr);
        
        
    }
};