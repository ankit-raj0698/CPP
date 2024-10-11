class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        string ans =  "";

        for(char ch: s){
            if(!stk.empty() && abs(ch - stk.top()) == 32)
                stk.pop();
            else
                stk.push(ch);
        }

        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};