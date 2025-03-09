class Solution {
public:
    double binPow(double x, long n){
        if(n == 0)
            return 1;
        
        if(n < 0){
            x = 1/x;
            n = -n;
        }

        double half = myPow(x,n/2);
        
        if(n % 2 == 0)   
            return half * half;
        else
            return x * half * half;
    }
    double myPow(double x, int n) {
        return binPow(x,(long)n);
    }
};