class Solution {
public:
    
    void reverse(vector<int>& nums,int start,int end){        
        while(start<=end){
            swap(nums[start++],nums[end--]);
        }        
    }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();

        //You were missing this edge case: [-1] k=2
        // [1,2] k=3 -> [2,1]
        k=k%n;
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);
        
    }
};