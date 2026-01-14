class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int maxLen = 0;
        int left = 0, right = 0;
        while(right < s.length()){

            while(set.contains(s.charAt(right))){
                set.remove(s.charAt(left++));
            }

            maxLen = Math.max(maxLen, right - left + 1);
            set.add(s.charAt(right));
            right++;
        }
        return maxLen;
    }
}