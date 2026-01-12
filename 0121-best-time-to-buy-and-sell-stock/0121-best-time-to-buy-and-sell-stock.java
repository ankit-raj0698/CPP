class Solution {
    public int maxProfit(int[] prices) {
        int mini = Integer.MAX_VALUE;
        int profit = 0;
        for(int ele: prices){
            mini = Math.min(mini,ele);
            int currProfit = ele - mini;
            profit = Math.max(profit, currProfit);
        }
        return profit;
    }
}