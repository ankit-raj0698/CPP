class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int len = nums.length;
        
        for(int i = 0; i < len; i++){

            // handle duplicates for i
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int target = -nums[i];
            int j = i + 1;
            int k = len - 1;
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum == target){
                    ans.add(List.of(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                    
                    // handle duplicates for j
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                    // handle duplicates for k
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
                else if(sum < target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
}