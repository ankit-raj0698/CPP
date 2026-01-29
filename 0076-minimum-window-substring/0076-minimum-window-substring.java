class Solution {
    public String minWindow(String s, String t) {
        Map<Character,Integer> mp = new HashMap<>();
        int left = 0, right = 0, count = 0;
        int minLen = Integer.MAX_VALUE;
        int startInd = -1;

        // store freq of each char in string t
        for(char ch: t.toCharArray())
            mp.put(ch, mp.getOrDefault(ch,0) + 1);
        
        // no. of unique char in t
        int reqCount = mp.size();

        while(right < s.length()){
            char ch = s.charAt(right);
            mp.put(ch, mp.getOrDefault(ch,0) - 1);

            if(mp.get(ch) == 0)
                count++;
            
            while(count == reqCount){
                
                int currLen = right - left + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                    startInd = left;
                }

                char currChar = s.charAt(left);
                mp.put(currChar, mp.getOrDefault(currChar, 0) + 1);
                if(mp.get(currChar) > 0)
                    count--;

                left++;
            }
            right++;
        }
        
        if(startInd != -1)
            return s.substring(startInd, startInd + minLen);
        return "";
    }
}