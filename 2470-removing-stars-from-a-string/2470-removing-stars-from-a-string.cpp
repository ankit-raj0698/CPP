class Solution {
public:
    string solveUsingTwoPointer(string s){
        int i = 0, j = 0;
        for(; i < s.length(); i++){
            if(s[i] == '*')
                j--;
            else
                s[j++] = s[i];
        }

        return s.substr(0,j);
    }

    string solveUsingStack(string s){
        stack<char> st;
        string ans = "";

        for(auto ch: s){
            if(ch == '*')
                st.pop();
            else
                st.push(ch);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string removeStars(string s) {
        // return solveUsingStack(s);
        return solveUsingTwoPointer(s);

    }
};