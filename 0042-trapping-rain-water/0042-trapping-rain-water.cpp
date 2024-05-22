class Solution {
public:
    /*
    two pointer approach
    iterate the loop while (left < right)
    maintain two variable leftmax and rightmax
    initialize leftmax = leftmost element of input array
    initialize rightmax = rightmost element of input array
    whichever is smaller among leftmax and rightmax update it
    if leftmax is smaller than rightmax do left++ otherwise right--
    tempWaterTrap = leftmax or rightmax - height[left] or height[right]
    if tempWaterTrap < 0 , do tempWaterTrap = 0
    store tempWaterTrap in ans
    update leftmax and rightmax accordingly    
    */
    
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        
        int leftmax = height[left];
        int rightmax = height[right];
        
        int ans = 0;
        
        while(left < right){
           
            if(leftmax < rightmax){
            left++;
            int res = leftmax - height[left];
            
            if(res < 0)
                res = 0;
                
            ans+=res;
            leftmax = max(leftmax,height[left]);
        }
        else{
            right--;
            int res = rightmax - height[right];
            
            if(res < 0)
                res = 0;
            
            ans+=res;
            rightmax = max(rightmax,height[right]);
        }            
    }      
        return ans;
    }
    
    
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
    
    /*
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
    */
};