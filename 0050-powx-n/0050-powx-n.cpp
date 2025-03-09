class Solution {
public:
    double binPow(double x, long n){
        if(n == 0)
            return 1;
        
        // handle negative exponent 
        if(n < 0){
            x = 1/x;
            n = -n;
        }

        // double half = binPow(x,n/2);
        
        if(n % 2 == 0){
            double temp = binPow(x, n/2);
            return temp * temp;
        }   
            
        else
            return x * binPow(x, n - 1);
    }
    double myPow(double x, int n) {
        //handle int overflow for exponent
        return binPow(x,(long)n);
    }
};