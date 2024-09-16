class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        int min1 = 1e5, min2 = 1e5;

        for(int ele : nums){
            if(ele > max2){
                if(ele > max1){
                    max2 = max1;
                    max1 = ele;
                }
                else
                    max2 = ele;
            }

            if(ele < min2){
                if(ele < min1){
                    min2 = min1;
                    min1 = ele;
                }
                else
                    min2 = ele;
            }
        }

        return (max2 * max1 - min2 * min1);
        
    }
};