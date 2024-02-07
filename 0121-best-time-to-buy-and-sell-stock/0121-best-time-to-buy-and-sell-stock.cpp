class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min=INT_MAX;
        int maxProfit=0;
        
        for(auto p:prices){
            
            if(p < min){
                min = p;
            }
            
            int profit = p-min ;
            if(profit > maxProfit){
                maxProfit = profit;
            }
            
        }
        return maxProfit;
    }
};