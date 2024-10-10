class Solution {
public:
    vector<int> findMin(vector<int> &prices){
        int mini = INT_MAX;
        int secondMin = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < mini){
                secondMin = mini;
                mini = prices[i];
            }
            else if(prices[i] < secondMin)
                secondMin = prices[i];
        }
        return {mini, secondMin};
    }
    int buyChoco(vector<int>& prices, int money) {
        //sort(prices.begin(), prices.end());

        vector<int> res = findMin(prices);
        int min1 = res[0];
        int min2 = res[1];

        //cout << min1 << min2<< endl;

        if(min1 + min2 <= money)
            money = money - min1 - min2;
        
        return money;
        
    }
};