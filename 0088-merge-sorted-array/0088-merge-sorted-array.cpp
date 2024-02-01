class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        while(i>=0 && j>=0){
            if(nums2[j]>=nums1[i]){
                nums1[k]=nums2[j];
                j--;
            }
            else{
                nums1[k]=nums1[i];
                i--;
            }
            k--;
        }
        // Hmlog nums1 m hi change kr rhe (nums1 ke end se )
        // max ele of nums1,nums2 end m hoga same process continue rakho
        // to jb nums2 ke sare element traverse kr liye
        // to ab bacha hua nums1 ka element to pehle se sorted hi h na
        // because nums1 ke unn elements ko to kch kiye hi nhi
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};