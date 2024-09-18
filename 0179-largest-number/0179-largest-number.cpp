class Solution {
public:
    struct compare{
        bool operator()(string a, string b){
            string first = a + b;
            string second = b + a;
            return first > second;
        }
    };

    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for(int ele : nums)
            strNums.push_back(to_string(ele));

        sort(strNums.begin(), strNums.end(), compare());

        if (strNums[0] == "0") return "0";

        string ans = "";
        for(string ele : strNums)
            ans += ele;
        
        return ans;
    }
};