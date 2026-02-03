class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int left = 0, right = 0, n = nums.length;
        Deque<Integer> q = new ArrayDeque<>();
        if(k > n)
            return new int[0];
        int[] ans = new int[n-k+1];
        int i = 0;
        
        while(right < n){
            int currEle = nums[right];

            while(!q.isEmpty() && q.peekLast() < currEle)
                q.pollLast();
            
            q.offer(currEle);
            
            if(right - left + 1 == k){
                ans[i++] = q.peek();

                if(q.peek() == nums[left])
                    q.poll();
                left++;
            }
            right++;
        }
        return ans;
    }
}