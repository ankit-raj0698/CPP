class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> count;
        for(auto ele:nums){
            count[ele]++;
        }
        
        vector<vector<int>> bucket(n+1);
        // i = freq
        // value = vector of elements having freq i
        for(auto it:count){
            int value = it.first;
            int freq = it.second;
            bucket[freq].push_back(value);
        }
        
        //iterate through the bucket from right to left
        vector<int> ans;
        for(int i = n; i > 0 ; i--){
            if(bucket[i].size()==0){
                continue;
            }
            while(bucket[i].size() > 0 && k > 0 ){
               ans.push_back(bucket[i].back());
               bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }

    
};