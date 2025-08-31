class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(),[](int a, int b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1+s2 > s2+s1;
        });

        string res = "";
        for(int ele: nums){
            res += to_string(ele);
        }

        if(res[0] == '0')
            return "0";

        return res;
    }
};