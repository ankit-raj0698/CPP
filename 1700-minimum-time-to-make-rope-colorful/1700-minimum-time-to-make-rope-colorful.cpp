class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int left = 0, right = 1, ans = 0;
        while(right < colors.size()){
            if(colors[left] != colors[right]){
                left = right;
                right++;
            }
            else{
                ans += min(neededTime[left], neededTime[right]);
                if(neededTime[left] < neededTime[right]){
                    left = right;
                    right++;
                }    
                else
                    right++;
            }
        }
       return ans; 
    }
};