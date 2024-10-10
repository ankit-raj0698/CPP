class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int open = 0;
        for(char ch: s){
            if(ch == '('){
                open++;
                ans = max(open,ans);
            }
            else if(ch == ')')
                open--;
        }
        return ans;
    }
};