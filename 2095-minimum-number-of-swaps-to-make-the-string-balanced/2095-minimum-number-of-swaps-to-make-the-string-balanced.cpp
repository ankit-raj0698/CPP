class Solution {
public:
    int minSwaps(string s) {
        
        stack<char> st;
        int res = 0;
        for(char ch: s){
            if(ch == '[')
                st.push('[');
            else{
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    st.push(']');                 
            }
        }

        int stackSize = st.size();

        // stack will contain same no. of opening and closing bracket
        int openCloseBracket = stackSize / 2;

        res = (openCloseBracket + 1) /2;

        return res;

    }
};