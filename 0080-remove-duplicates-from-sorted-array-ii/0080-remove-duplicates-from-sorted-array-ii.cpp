class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=0;
        // Acc to question : element can appear atmost twice
        // to i=0,1 ko "if" block m handle kro
        // jis bhi index m new element insert hoga i.e "i" index
        // wahan pe khada hoke pucho ki usse 2 element pehle kaun h 
        // i.e.. "i-2" index pe kaun h 
        // Agar "i-2" index pe diff element h current index i.e.."j" index se
        // to mtlb "i" index pe insert kr skte h
        for(int j=0;j<nums.size();j++){
            if(j == 0 || j == 1 || nums[i-2] != nums[j]){
                nums[i++] = nums[j];
            }
        }

        return i;

    }
};