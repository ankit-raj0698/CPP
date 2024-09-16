class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        unordered_set<int> s;
        for(int ele : nums1)
            s.insert(ele);

        for(int ele: nums2){
            if(s.find(ele) != s.end()){
                res.push_back(ele);
                s.erase(ele);
            }
        }
        return res;
    }
};