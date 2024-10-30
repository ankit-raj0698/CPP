class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0, jump = 0;
        int n = nums.size();

        while(right < n - 1){
            int maxIndexReachable = 0;

            for(int i = left; i <= right; i++){
                maxIndexReachable = max(maxIndexReachable, i + nums[i]);
            }

            left = right + 1;
            right = maxIndexReachable;
            jump++;
        }
        return jump;
    }
};