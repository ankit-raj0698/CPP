class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        unordered_set<int> s;
        for(auto ele:nums){
            s.insert(ele);
        }
        int maxLength = INT_MIN;
        for(auto ele:s){
            if(s.find(ele-1) == s.end()){
                int length = 1;
                while(s.find(ele+length) != s.end())
                    length++;
                maxLength = max(maxLength,length);
            }              
        }
        return maxLength;
    }
    
    /*
    // take a lastSmaller = INT_MIN and initial length to be 1
    // iterate through the array starting from "0" to "n-1"
    // check if "arr[i] - 1" is less than lastSmaller then it is part of consecutive sequence
    // so update the length that is length++ and lastSmaller to be current element i.e.. arr[i]
    // if "arr[i] == lastSmaller" then no need to do anything simply skip
    // if "arr[i] != lastSmaller" so it means that we are getting a new sequence
    // so update the length = 1 and lastSmaller to be current element i.e.. arr[i]
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
    */
};