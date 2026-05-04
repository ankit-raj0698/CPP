class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        Arrays.fill(used, false);

        solve(nums, 0, new ArrayList<>(), ans, used);
        return ans;
    }

    public void solve(int[] nums, int start, List<Integer> temp, List<List<Integer>> ans, boolean[] used){

        if(temp.size() == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i = 0; i < nums.length; i++){

            if(used[i] == true)
                continue;

            temp.add(nums[i]);
            used[i] = true;

            solve(nums, i, temp, ans, used);

            temp.remove(temp.size() - 1);
            used[i] = false;
        }
    }
}