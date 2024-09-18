class Solution {
public:

    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int left = 0, right = 0;
        while(right < s.size()){

            while(right - left + 1 > k){
                left++;
            }

            if(right - left + 1 == k){
                string str = s.substr(left, right - left + 1);
                st.insert(str);
            }
            right++;
        }
        if(st.size() == 1 << k)
            return true;
        
        return false;
        
    }
};