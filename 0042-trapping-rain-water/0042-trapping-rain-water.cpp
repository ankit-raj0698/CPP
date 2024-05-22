class Solution {
public:
    
    
    
    /*
    solution with time complexity O(n) and space complexity O(n)
    let total water to be trapped be ans = 0;
    create two vectors leftmax and rightmax of size n
    leftmax[i] --> max of all the elemments to the left of i
    rightmax[i] --> max of all the elemments to the right of i
    LOGIC : res = min(leftmax[i],rightmax[i]) - height[i]
    if res < 0 then make res = 0
    ans = ans + res
    */
    
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        
        leftmax[0] = 0;
        rightmax[n-1] = 0;
        
        for(int i=1; i<n; i++){
            leftmax[i] = max(leftmax[i-1],height[i-1]);
        }
        
        for(int i=n-2; i>=0; i--){
            rightmax[i] = max(rightmax[i+1],height[i+1]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int res = min(leftmax[i],rightmax[i]) - height[i];
            if(res < 0){
                res = 0;
            }
            ans+=res;
        }
        return ans;
    }
};