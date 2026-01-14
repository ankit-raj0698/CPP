class Solution {
    public int characterReplacement(String s, int k) {
        int left = 0, right = 0, maxFreq = 0, maxLen = 0, n = s.length();

        int[] freq = new int[26];
        while(right < n){
            freq[s.charAt(right) - 'A']++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(right) - 'A']);

            if(right - left + 1 - maxFreq > k){
                freq[s.charAt(left) - 'A']--;
                left++;
            }

            if(right - left + 1 - maxFreq <= k)
                maxLen = Math.max(right - left + 1, maxLen);
            right++;
        }
        return maxLen;
    }
}