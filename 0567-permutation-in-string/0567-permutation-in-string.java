class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int k = s1.length();
        int[] freqS1 = new int[26];
        for(int i = 0; i < k; i++){
            char ch = s1.charAt(i);
            freqS1[ch - 'a']++;
        }

        for(int i = 0; i <= s2.length() - k; i++){
            int[] freqS2 = new int[26];
            for(int j = i; j < (i + k); j++){
                char ch = s2.charAt(j);
                freqS2[ch - 'a']++;
            }
            if(Arrays.equals(freqS1, freqS2))
                return true;
        }
          return false;  
    }
}