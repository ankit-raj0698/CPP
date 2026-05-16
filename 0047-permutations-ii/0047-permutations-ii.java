class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        boolean[] used = new boolean[nums.length];
        Arrays.fill(used, false);
        List<List<Integer>>  ans = new ArrayList<>();
        permute(nums, used, new ArrayList<>(), ans);
        return ans;
    }

    void permute(int[] nums, boolean[] used, List<Integer> temp, List<List<Integer>> ans){
        if(temp.size() == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i = 0; i < nums.length; i++){

            if(used[i])
                continue;
            
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            temp.add(nums[i]);

            permute(nums, used, temp, ans);

            used[i] = false;
            temp.remove(temp.size() - 1);
        }
    }
}