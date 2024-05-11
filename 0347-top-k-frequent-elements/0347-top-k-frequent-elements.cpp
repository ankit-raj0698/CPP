class Solution {
public:
    /*
    create an unordered map to count frequency of each element
    create a 2D vector to store freq in "i" and vector of elements in "j" that is this 2D       vector will contain vector of elements corresponding to the count of element
    iterate through this 2D vector from size()-1 and push_back the elements in answer
    when size of answer is equal to k return the answer
    */
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