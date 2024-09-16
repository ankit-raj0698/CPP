class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n+1,false);
        vector<int> res;

        for(int i = 0; i < n; i++){
            if(visited[nums[i]])
                res.push_back(nums[i]);
            
            visited[nums[i]] = true;
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i])
                res.push_back(i);
        }  

        return res;   
    }
};