class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int maxlen = 0;
        if(nums.size() == 0)
            return 0;
        
        unordered_set<int> st;
        for(int ele: nums){
            st.insert(ele);
        }
        
        for(auto ele:st){
            //when element is starting of the sequence in set, calculate the length of sequence
            if(st.find(ele - 1) == st.end()){
                int length = 1;
                while(st.find(ele + 1) != st.end()){
                    length++;
                    ele = ele + 1;
                }
                maxlen = max(maxlen,length);
            }
        }
        return maxlen;
        
    }
};