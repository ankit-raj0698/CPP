class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n); 
        vector<int> right(n);
        int leftmax = height[0];
        int rightmax = height[n-1];

        for(int i = 0; i < n; i++){
            left[i] = leftmax;
            leftmax = max(leftmax, height[i]);
        } 

        for(int i = n-1; i >= 0; i--){
            right[i] = rightmax;
            rightmax = max(rightmax, height[i]);
        }
            
        int total = 0;
        for(int i = 0; i < n; i++){
            
            int waterTrapped = min(left[i], right[i]) - height[i];
            // when waterTrapped < 0, then add 0 to total
            total += waterTrapped < 0 ? 0 : waterTrapped;
            
        }

         return total;   
    }
};