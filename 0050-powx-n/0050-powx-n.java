class Solution {
    public double solve(double x, long n){
        if(n == 0)
            return 1.0;
        double half = solve(x, n / 2);
        if(n % 2 == 0)
            return half * half;
        return x * half * half;
    }
    public double myPow(double x, int n) {
        long N = n;
        if(N < 0)
            return solve(1/x, -N);
        return solve(x,N);
    }
}