class Solution {
public:
    bool solve(int n){

        if(n == 1)
            return true;
        // odd no and 0 can't be power of 2
        if(n % 2 == 1 || n == 0)
            return false;
        
        return solve(n/2);
    }
    bool isPowerOfTwo(int n) {
        // 0 and -ve no can't be power of 2
        if(n <= 0)
            return false;
        
        return solve(n);
    }
};