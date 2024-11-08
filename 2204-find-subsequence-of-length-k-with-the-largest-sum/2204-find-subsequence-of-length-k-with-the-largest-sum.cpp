class Solution {
public:
    typedef pair<int, int> t;
    bool static comparator(t &a, t &b){
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<t, vector<t>, greater<t>> pq;
        vector<t> temp;
        vector<int> ans;

        if(nums.size() < k)
            return {};

        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
            if(pq.size() > k)
                pq.pop();
        }

        while(!pq.empty()){
            temp.push_back(pq.top());
            pq.pop();
        }

        sort(temp.begin(), temp.end(), comparator);   
        for(auto it: temp)
            ans.push_back(it.first);
        return ans;
    }
};