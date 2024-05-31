class Solution {
public:
    
    void solve(vector<int> &nums,vector<int> temp,vector<vector<int>> &ans,unordered_set<int> s){
       if(temp.size() == nums.size()){
           ans.push_back(temp);
           return;
       } 
        // iterate through all the elements of array
        for(int i = 0 ; i< nums.size(); i++){
            // when element is not explored
            if(s.find(nums[i]) == s.end()){
                
                temp.push_back(nums[i]);
                s.insert(nums[i]);
                
                solve(nums, temp, ans, s);
                
                temp.pop_back();
                s.erase(nums[i]);
            }         
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_set<int> s;
        
        solve(nums,temp,ans,s);
        
        return ans;
    }
};