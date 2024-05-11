class Solution {
    
public:
    /*
    OPTIMAL SOLUTION 
    declare answer vector with size n
    Store left product directly in answer
    initialize right product = 1
    iterate through the answer vector starting from "n-1"
    multiply current element with right product and update right product everytime
    
    */
    
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        //Store left product directly in answer
        ans[0] = 1;
        for(int i=1; i<n;i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        //multiply current element with right product and update right product everytime
        int rightProduct = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] = ans[i] * rightProduct;
            rightProduct = rightProduct * nums[i];
        }
        return ans;
    }
    
    /*
    WITHOUT DIVISION but using extra space
    // create a left vector to store product of all elements to the left of current element
    // create a right vector to store product of all elements to the right of current element
    // Note: declare size of each vector(nums.size()) otherwise you will get runtime error
    // multiply left[i] and right[i] and store it in answer
    
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0]=1;
        for(int i=1;i<n;i++){
            left[i] = left[i-1] * nums[i-1];
        }
        
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
    
    */
    
    
    // WITH DIVISION
    //(find the product of all element and divide with current element)
    // find product of all elements , product of all non zero element , count of zeros
    // if count of zeros is greater than equal to 2, return answer with all zeros
    // if current element is zero, answer will be (product of all non zero element)
    // else answer is (product of all element)/(current element)
    
    /*
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
    */
};