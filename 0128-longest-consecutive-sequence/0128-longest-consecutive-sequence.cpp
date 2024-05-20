class Solution {
public:
    
   /*
   // insert all the elements of input array in an unordered set
   // iterate through all the elements of unordered set
   // if current element is nums[i] and nums[i] - 1 is present in the set Then
   // it means that this is not the starting point of the sequence so skip it
   // if current element is nums[i] and "nums[i] - 1 is not present" in the set then
   // assign length = 1 and use a while loop
   // iterate in the loop until nums[i] + length does not exist in the set
   // in the while loop increment the length by 1
   // check the maxLength and update accordingly
   
   */
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        unordered_set<int> s;
        for(auto ele:nums){
            s.insert(ele);
        }
        
        int maxLength = 1;
        
        for(auto ele:s){
            
            if(s.find(ele-1) == s.end()){   
                int length = 1;
                int n = ele;
                
                while(s.find(ele + 1) != s.end()){
                    length++;
                    ele = ele + 1;
                }  
                
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
        int maxLength = 1;
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