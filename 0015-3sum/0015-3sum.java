class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);

        int len = nums.length;
        for(int i = 0; i < len; i++){

            // handle duplicate i
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int target = -nums[i];
            int j = i + 1;
            int k = len - 1;
            while(j < k){
                if(nums[j] + nums[k] == target){
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(nums[k]);
                    j++;
                    k--;
                    ans.add(temp);

                    while(j < k && nums[j] == nums[j-1])
                        j++;
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
                else if(nums[j] + nums[k] < target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
}