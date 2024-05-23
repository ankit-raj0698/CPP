class Solution {
public:
    /*
    use sliding window left =0 and right = 1
    iterate the loop until right pointer exceeds size of input array
    if it is a profitable transaction then calculate profit and update maxprofit
    otherwise move the left pointer to right as we have got a day where left is smaller than prev value
    increment right everytime
    */
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;
        
        while(right < prices.size()){
            if(prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit,profit);              
            }
            else{
                left = right;
            }
            right++;            
        }
       return maxProfit; 
    }
};