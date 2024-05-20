class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size();
        int maxLength = INT_MIN;
        int lastSmaller = INT_MIN;
        int length = 1;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmaller){
                lastSmaller = nums[i];
                length++;
            }
            // if(arr[i] == lastSmaller) continue;
            else if(nums[i] != lastSmaller){
                lastSmaller = nums[i];
                length = 1; 
            }
            maxLength = max(maxLength,length);
        }        
        return maxLength;               
    }
};