class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i=0;

        // Acc to question : element can appear atmost once
        // to i=0 ko "if" block m handle kro
        // jis bhi index m new element insert hoga i.e "i" index
        // wahan pe khada hoke pucho ki usse 1 element pehle kaun h 
        // i.e.. "i-1" index pe kaun h 
        // Agar "i-1" index pe diff element h, current element i.e.."j" index se
        // to mtlb "i" index pe current element i.e.. "j" index ko insert kr skte h

        for(int j=0;j<nums.size();j++){
            if(j == 0 || nums[i-1] != nums[j]){
                nums[i++] = nums[j];
            }
        }
       return i; 
    }
};