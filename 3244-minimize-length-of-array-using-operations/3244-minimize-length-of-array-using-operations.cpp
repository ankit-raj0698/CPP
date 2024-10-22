class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {

        // a < b then a % b = a
        // so with the help of smaller no we can delete greater no
        // find the min element and try to remove all the bigger element
        // before that check if you can generate any no less than min element
        // then you can delete all the other element with the help of this no

        int mini = *min_element(nums.begin(), nums.end());
        // see if you can generate any no > 0 but less than min element
        for(auto ele: nums){
            if(ele % mini > 0)
                return 1; // only this element will be left at end
        }
        // find the freq of mini
        int freq = 0;
        for(auto ele: nums){
            if(ele == mini)
                freq++;
        }
        // with the help of mini we will reduce greater element
        // then in the end we will only be left with all mini element in array
        return (freq + 1)/2;
    }
};