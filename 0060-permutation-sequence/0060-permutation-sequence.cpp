class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
            fact *= i;
        }

        fact /= n;
        k = k - 1; // 0 based indexing
        string ans = "";

        while(true){
            ans.push_back(nums[k/fact] + '0');
            nums.erase(nums.begin() + (k/fact));

            if(nums.size() == 0)
                break;
            
            k = k % fact;
            fact = fact / nums.size();          
        }

        return ans;
    }
};