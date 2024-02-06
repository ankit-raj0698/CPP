class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        /*unordered_map<int,int> mp;
        int n=nums.size();
        int ans=-1;  
        //store freq of every element in map
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;          
        }  
        // Iterate through map to find majority element
        for(auto i:mp){
            if(i.second > (n/2)){
                ans = i.first;
            }          
        }
       return ans;*/

        //Moore voting algorithm
       int count=0;
       int candidate=0;

       for(int i=0;i<nums.size();i++){
           if(count==0){
               candidate=nums[i];
           }

           if(nums[i]==candidate){
               count++;
           }
           else{
               count--;
           }
       } 
       return candidate;
    }
};