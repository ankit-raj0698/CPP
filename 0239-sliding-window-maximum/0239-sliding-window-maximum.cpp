class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;

        // to track the max in window
        list<int> l;

        int left = 0, right = 0;
        while(right < nums.size()){

            // when we encounter a greater no in the current window
            // then all the prev smaller no are useless
            // but smaller no after curr element can be useful for other window
            while(!l.empty() && l.back() < nums[right])
                l.pop_back();
            l.push_back(nums[right]);

            if(right - left + 1 == k){
                // store the answer
                ans.push_back(l.front());

                // shrink the window from left side
                // since we have to maintain size of k, just check for nums[left]
                if(l.front() == nums[left])
                    l.pop_front();
                
                left++;               
            }
            right++;
        }
        return ans;
    }
};