class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n+1];
        ans[0] = 0;

        for(int i = 1; i <= n; i++){
            int setBits = 0;
            int m = i;
            while(m != 0){
                if((m & 1) == 1)
                    setBits++;
                m= m >> 1;
            }
            ans[i] = setBits;
        }
        return ans;
    }
}