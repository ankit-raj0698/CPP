class Solution {
    int n;
    public void solve(int[] nums, int ind, List<Integer> temp, List<List<Integer>> ans){
        if(ind >= n){
            ans.add(new ArrayList<>(temp));
            return;
        }

        // take
        temp.add(nums[ind]);
        solve(nums, ind + 1, temp, ans);

        // remove
        temp.remove(temp.size() - 1);

        // not take
        solve(nums, ind + 1, temp, ans);

    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        n = nums.length;
        solve(nums, 0, new ArrayList<>(), ans);
        return ans;
    }
}