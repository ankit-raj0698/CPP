class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "", res = "";
        int openCnt = 0;

        // remove extra closing parenthesis
        for(char ch: s){
            if(ch == '('){
                openCnt++;
                ans += ch;
            }
            else if(ch == ')' && openCnt > 0){
                openCnt--;
                ans += ch;
            }
            else if(ch != '(' && ch != ')')
                ans += ch;
        }

        // remove extra opening parenthesis
        // remove all the extra rightmost opening bracket

        for(int i = ans.size()-1; i >= 0; i--){
            char ch = ans[i];

            if(ch == '(' && openCnt > 0)
                openCnt--;
            else
             res += ch;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};