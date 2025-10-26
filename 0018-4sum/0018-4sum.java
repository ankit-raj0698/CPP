class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);
        for(int i = 0; i <= n - 4; i++){
            // handle duplicates for i
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i + 1; j <= n - 3; j++){
                // handle duplicates for j
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // use long to avoid integer overflow
                long newTarget = (long)target - nums[i] - nums[j];
                int k = j + 1, l = n - 1;
                while(k < l){
                    // use long to avoid integer overflow
                    long sum = nums[k] + nums[l];
                    if(sum == newTarget){
                        ans.add(List.of(nums[i], nums[j], nums[k], nums[l]));
                        k++;
                        l--;

                        // handle duplicates for k
                        while(k < l && nums[k] == nums[k - 1])
                            k++;
                        // handle duplicates for l
                        while(k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if(sum < newTarget)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }
}