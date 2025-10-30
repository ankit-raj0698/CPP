class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length();
        int[] ans = new int[n + 1];
        int k = 0;

        int min = 0;
        int max = n;

        for(int i = 0; i < n; i++){
            if(s.charAt(i) == 'I'){
                ans[k++] = min;
                min++;
            }
            else{
                ans[k++] = max;
                max--;
            }
        }
        ans[k] = min;
        return ans;
    }
}