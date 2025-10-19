class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        List<Integer> lessThan = new ArrayList<>();
        List<Integer> equal = new ArrayList<>();
        List<Integer> greaterThan = new ArrayList<>();

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot)
                lessThan.add(nums[i]);
            else if(nums[i] == pivot)
                equal.add(nums[i]);
            else
                greaterThan.add(nums[i]);
        }

        lessThan.addAll(equal);
        lessThan.addAll(greaterThan);

        // int[] ans = new int[n];
        // for(int i = 0; i < lessThan.size(); i++)
        //     ans[i] = lessThan.get(i);
        // return ans;

        return lessThan.stream().mapToInt(i -> i).toArray();
    }
}