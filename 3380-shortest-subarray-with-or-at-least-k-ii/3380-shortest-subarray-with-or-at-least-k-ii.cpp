class Solution {
public:
    void updateBits(vector<int> &bitcount, int num, int diff){
        for(int i = 0; i < 32; i++){
            // check if ith bit of num is 1
            if(num & (1 << i))
            // if the ith bit is 1, then update the count in bit vector
                bitcount[i] += diff;
        }
    }

    int bit_to_num(vector<int> &bitcount){
        int res = 0;
        for(int i = 0; i < 32; i++){
            // if current bit is set, then create the decimal no
            if(bitcount[i])
             // say bitcount array has 2,0,1,4
             // then decimal no would be 13 : 1 * 2^0 + 0 + 1 * 2^2 + 1 * 2^3
             // we just need if bit is set or not , not interested in count of ith bit
                res += (1 << i);
        }
        return res;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size();
        vector<int> bitcount(32, 0);
        int curror = 0;
        int ans = INT_MAX;

        while(right < n){
            // increment the set bit count
            updateBits(bitcount, nums[right], 1);
            curror = bit_to_num(bitcount);

            while(curror >= k && left <= right){
                ans = min(ans, right - left + 1);
                // decrement the set bit count
                updateBits(bitcount, nums[left], -1);
                curror = bit_to_num(bitcount);
                left++;
            }
            right++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};