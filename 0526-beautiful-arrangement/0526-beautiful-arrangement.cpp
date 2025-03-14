class Solution {
public:
    void solve(vector<int> &nums, int l, int r, int &count){

        if(l == nums.size()){
            count++;
            return;
        }

        for(int i = l; i <= r; i++){
            swap(nums[l], nums[i]);
            // after swap ith element came to lth index
            // so check if lth index element is valid
            if(nums[l] %( l+1) == 0 || (l + 1) % nums[l] == 0)
                solve(nums, l + 1, r, count);
            swap(nums[l], nums[i]);
        }
    }
    int countArrangement(int n) {
        int count = 0;
        vector<int> nums(n,0);
        for(int i = 0; i < n; i++)
            nums[i] = i + 1;
        
        solve(nums, 0, n-1, count);
        return count;
        
    }
};