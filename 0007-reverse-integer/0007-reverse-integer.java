class Solution {
    public int reverse(int x) {
        int n = x;
        int sum = 0;
        boolean isNeg = false;
        if(n < 0){
            isNeg = true;
            n = -n;
        }

        while(n > 0){
            int rem = n % 10;
            if(sum > Integer.MAX_VALUE / 10 || sum < Integer.MIN_VALUE / 10)
                return 0;
            sum = sum * 10 + rem;
            n = n / 10;
        }
        if(isNeg)
            return -sum;
        return sum;
    }
}