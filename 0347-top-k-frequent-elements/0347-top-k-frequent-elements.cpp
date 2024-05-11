class Solution {
public:
    /*
    create an unordered map to store freq of each element
    create a 2D bucket vector to store freq of element as index "i" and index "j" as vector     of elements with freq "i"
    iterate through the bucket vector from right to left
    if bucket[i] is not empty and k > 0 push the element in answer and decrement k and pop that element from bucket[i]
    */
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