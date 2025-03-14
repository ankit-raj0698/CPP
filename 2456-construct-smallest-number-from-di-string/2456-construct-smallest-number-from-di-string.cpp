class Solution {
public:
    string smallestNumber(string pattern) {
        int count = 0;
        stack<int> st;
        string ans = "";
        for(int i = 0; i <= pattern.size(); i++){

            count++;
            if(pattern[i] == 'I' || i == pattern.size()){
                ans.push_back(count + '0');
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            else if(pattern[i] == 'D'){
                st.push(count + '0');
            }
        }
        return ans;
    }
};