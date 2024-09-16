class Solution {
public:
    // using sorting and binary search
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int x = 0; x <= n; x++){
            // count numbers that are greater than x
            // since array is sorted, lower bound will index of element
            // that is just greater than or equal to x
            int ind = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            int count = n - ind;

            if(x == count)
                return x;
        }
        return -1;
    }

    // brute force : n*n
    /*
    int specialArray(vector<int>& nums) {
        for(int i = 0; i <= nums.size(); i++){
            int x = i;
            int cnt = 0;

            for(int j = 0; j < nums.size(); j++){
                if(nums[j] >= x)
                    cnt++;
            }

            if(cnt == x)
                return x;
        }
        return -1;
    }
    */
};