class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        solve(candidates, target, 0, new ArrayList<>(), ans);
        return ans;
    }

    public void solve(int[] candidates, int target, int start, List<Integer> temp, List<List<Integer>> ans){

        if(target == 0){
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i = start; i < candidates.length; i++){
            // if(candidates[i] <= target){
            //     if(i > start && candidates[i] == candidates[i - 1])
            //         continue;
            //     temp.add(candidates[i]);
            //     solve(candidates, target - candidates[i], i + 1, temp, ans);
            //     temp.remove(temp.size() - 1);
            // }

            if(candidates[i] > target)
                break;
            
            if(i > start && candidates[i] == candidates[i - 1])
                    continue;

            temp.add(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, temp, ans);
            temp.remove(temp.size() - 1);
        }
    }
}