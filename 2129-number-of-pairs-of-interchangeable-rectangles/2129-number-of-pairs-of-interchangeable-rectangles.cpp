class Solution {
public:

    // Note:
    // cast to double when finding the ratio
    // cast to long long when finding the pair count
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {

        unordered_map<double, int> mp;
        double ratio ;
        for(auto &vec: rectangles){
            int w = vec[0];
            int h = vec[1];
            ratio = (double) w/h;

            mp[ratio]++;

        }
        long long ans = 0;
        for(auto &[key, val] : mp){
            ans += (long long)val*(val - 1)/2;
        }

        return ans;
        
    }
};