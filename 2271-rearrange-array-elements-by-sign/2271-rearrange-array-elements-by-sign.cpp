class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);
        int i = 0, j = 1;
        for(int ele: nums){
            if(ele > 0){
                ans[i] = ele;
                i += 2;
            }
            else{
                ans[j] = ele;
                j += 2;
            }
        }
        return ans;
    }
};