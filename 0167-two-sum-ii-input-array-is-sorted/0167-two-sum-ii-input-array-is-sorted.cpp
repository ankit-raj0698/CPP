class Solution {
public:
    
    /*
    use two pointer approach, i= leftmost index and j= rightmost index of input array
    if sum == target return index i,j (in question vector is 1 based indexing so do i+1,j+1)
    if sum < target so we have to increase sum to go towards target so move right that is i++
    if sum > target so we have to decrease sum to go towards target so move left that is j--
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> ans;
        
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(sum < target){
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};