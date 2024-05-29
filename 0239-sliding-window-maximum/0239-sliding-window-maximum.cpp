class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int left = 0, right = 0;
        list<int> l;
        vector<int> ans;
        
        while(right < nums.size()){
            //calculations
           // say currently we are at index right so all the no smaller than s[right] 
            // from back of list should be deleted
                while(!l.empty() && l.back() < nums[right]){
                    l.pop_back();
                }
                l.push_back(nums[right]);
            
            
            //window size == k
            if(right - left + 1 == k){
                ans.push_back(l.front());
            
            //slide the window
            if(l.front() == nums[left]){
                l.pop_front();
            }
            left++;
            }         
            right++;            
        }
      return ans;  
    }
};