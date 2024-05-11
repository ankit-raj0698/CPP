class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;
        if(!nums.size()){
            return res;
        }
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size()+1);
        for(auto ele:nums){
            count[ele]++;
        }
        for(auto ele:count){
            freq[ele.second].push_back(ele.first);
        }
        
        for(int i=freq.size()-1;i>=0;i--){
            for(int j=0;j<freq[i].size();j++){
                res.push_back(freq[i][j]);
                if(res.size() == k)               
                    return res;
            }
            
        }
       return res; 
    }
};