class Solution {

    static class Pair {
        int first, second;
        Pair(int f, int s) {
            this.first = f;
            this.second = s;
    }
}

    public int maximumGap(int[] nums) {
        int maxGap = 0;
        if(nums.length < 2)
            return 0;

        int minEle = Integer.MAX_VALUE;
        int maxEle = 0;
        int n = nums.length;

        for(int ele: nums){
            minEle = Math.min(minEle, ele);
            maxEle = Math.max(maxEle, ele);
        }

        //PigeonHole Principle:  idea is to distribute N no. into N - 1 holes
        int bucketSize = (int)(Math.ceil((double)(maxEle - minEle)/(n-1)));

        List<Pair> list = new ArrayList<>();
        for(int i = 0; i < n - 1; i++){
            list.add(new Pair(Integer.MAX_VALUE, Integer.MIN_VALUE));
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] == minEle || nums[i] == maxEle)
                continue;
            
            int ind = (nums[i] - minEle)/bucketSize;
            
            Pair p = list.get(ind);
            p.first = Math.min(p.first, nums[i]);
            p.second = Math.max(p.second, nums[i]);

        }

        int prevMax = minEle;
        for(int i = 0; i < n - 1; i++){
            Pair p = list.get(i);
            if(p.second == Integer.MIN_VALUE)
                continue;
            
            maxGap = Math.max(maxGap, p.first - prevMax);
            prevMax = p.second;
        }

        maxGap = Math.max(maxEle - prevMax, maxGap);
        return maxGap;
        
    }
}