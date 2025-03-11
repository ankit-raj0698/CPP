class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long a, long long n){
        if(n == 0)
            return 1;
        long long half = power(a, n/2) % mod;
        half = (half * half) % mod;

        if(n % 2 == 1)
            half = ((a % mod) * half) % mod;
        
        return half % mod;
        
    }

    int minNonZeroProduct(int p) {

        long long maxi = (1LL << p) -1;
        return ((maxi % mod) * power(maxi-1, maxi/2)) % mod;
        
    }
};