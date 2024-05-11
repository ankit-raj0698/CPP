class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int product = 1;
        int productWithoutZero = 1;
        int nonZeroCount = 0;
        int n = nums.size();
        
        for(auto ele:nums){
            product*=ele;
            if(ele != 0){
                nonZeroCount++;
                productWithoutZero*=ele;
            }
        }
        
        int zeroCount = n - nonZeroCount;
        vector<int> ans(n,0);
        
        if(zeroCount >= 2){
            return ans;
        }
        
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                ans[i] = productWithoutZero;
            }
            else{
                ans[i] = (product/nums[i]);
            }
            
        }
        return ans;  
    }
};