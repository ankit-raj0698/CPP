class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size()-1, score = 0, ans = 0;
        while(left <= right){
            if(tokens[left] <= power){
                score++;
                power -= tokens[left];
                left++;
                ans = max(ans, score);
            }
            else if(score > 0){
                score--;
                power += tokens[right];
                right--;
            }
            else
                break;
        }
        return ans;
    }
};