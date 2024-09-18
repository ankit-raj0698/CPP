class Solution {
public:
    
    int countPalindromicSubsequence(string s) {

        // store all unique char in set
        unordered_set<char> letter;
        for(char ch: s)
            letter.insert(ch);
        
        int res = 0;

        // iterate over each unique char of string
        for(char ch: letter){
            
            // find the left most and right most index of each unique char
            int left_ind = -1;
            int right_ind = -1;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == ch){
                    if(left_ind == -1)
                        left_ind = i;
                    
                    right_ind = i;
                }
            }

            // find unique char between left and right index
            unordered_set<char> st;
            for(int i = left_ind + 1; i <= right_ind - 1; i++)
                st.insert(s[i]);
            
            res += st.size();

        }
        
        return res;
    }
};