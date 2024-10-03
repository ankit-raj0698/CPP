class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> first(nums1.begin(), nums1.end());
        unordered_set<int> second(nums2.begin(), nums2.end());

        // Use sets to store unique elements.
        unordered_set<int> uniqueInNums1;
        unordered_set<int> uniqueInNums2;

        // Find elements in nums1 that are not in nums2.
        for(int ele: nums1) {
            if(second.find(ele) == second.end()) {
                uniqueInNums1.insert(ele);
            }
        }

        // Find elements in nums2 that are not in nums1.
        for(int ele: nums2) {
            if(first.find(ele) == first.end()) {
                uniqueInNums2.insert(ele);
            }
        }

        // Prepare the result by converting sets back to vectors.
        vector<vector<int>> ans(2);
        ans[0] = vector<int>(uniqueInNums1.begin(), uniqueInNums1.end());
        ans[1] = vector<int>(uniqueInNums2.begin(), uniqueInNums2.end());

        return ans;
    }
};