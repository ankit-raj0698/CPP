class Solution {
public:
    bool solve(int n){
        if(n == 1)
            return true;
        if(n % 2 == 1)
            return false;
        
        return solve(n/2);
    }
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        
        return solve(n);
    }
};