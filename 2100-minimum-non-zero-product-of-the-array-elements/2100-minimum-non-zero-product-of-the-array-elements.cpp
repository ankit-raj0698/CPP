class Solution {
public:
    int mod = 1e9 + 7;

    int power(long long a, long long n){
        if(n == 0){
            return 1;
        }

        long long half = power(a, n/2);
        half = (half * half) % mod;

        if(n % 2 == 1){
            half = (half * (a % mod)) % mod;
        }
        return half % mod;
    }
    int minNonZeroProduct(int p) {
        
        long long x = (1LL << p) - 1;
        return  x % mod  * power(x-1, x/2) % mod;  
    }
};
