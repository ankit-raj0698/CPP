class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        List<Integer> even = new ArrayList<>();
        List<Integer> odd = new ArrayList<>();

        for(int ele: nums){
            if(ele % 2 == 0)
                even.add(ele);
            else
                odd.add(ele);
        }
        int[] ans = new int[nums.length];
        int j = 0, k = 0;
        for(int i = 0; i < nums.length; i++){
            if(i % 2 == 0){
                ans[i] = even.get(j);
                j++;
            }
            else{
                ans[i] = odd.get(k);
                k++;
                }
        }
        return ans;
    }
}