class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length();
        int[] ans = new int[n + 1];
  
        int min = 0;
        int max = n;

        for(int i = 0; i < n; i++){
            if(s.charAt(i) == 'I'){
                ans[i] = min;
                min++;
            }
            else{
                ans[i] = max;
                max--;
            }
        }
        ans[n] = min;
        return ans;
    }
}