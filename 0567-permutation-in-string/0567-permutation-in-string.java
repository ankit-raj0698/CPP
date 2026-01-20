class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int k = s1.length();
        int[] freqS1 = new int[26];
        for(int i = 0; i < k; i++){
            char ch = s1.charAt(i);
            freqS1[ch - 'a']++;
        }

        int[] freqS2 = new int[26];
        int left = 0, right = 0, n = s2.length();

        while(right < n){
            char ch = s2.charAt(right);
            freqS2[ch - 'a']++;

            while(right - left + 1 > k){
                freqS2[s2.charAt(left) - 'a']--;
                left++;
            }

            if(right - left + 1 == k){
                if(Arrays.equals(freqS1, freqS2))
                    return true;
            }
            right++;
        }
          return false;  
    }
}