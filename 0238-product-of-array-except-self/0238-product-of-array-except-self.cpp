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
        vector<int> ans;
        
        if(zeroCount >= 2){
            for(int i=0;i<nums.size();i++){
                ans.push_back(0);
            }
            return ans;
        }
        
        for(auto ele:nums){
            if(ele == 0){
                ans.push_back(productWithoutZero);
            }
            else{
                ans.push_back(product/ele);
            }
            
        }
        return ans;  
    }
};