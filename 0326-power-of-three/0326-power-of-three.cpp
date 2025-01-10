class Solution {
public:
    bool solve(int n){
        if(n == 1)
            return true;
        if(n == 0 || n % 3 != 0)
            return false;
        return solve(n/3);
    }
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        return solve(n);
    }
};