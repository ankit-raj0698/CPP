class Solution {
    public String customSortString(String order, String s) {

        StringBuilder sb = new StringBuilder();
        Set<Character> set = new HashSet<>();
        int[] freq = new int[26];

        for(char ch: order.toCharArray())
            set.add(ch);

        for(char ch: s.toCharArray()){
            if(!set.contains(ch))
                sb.append(ch);
            else
                freq[ch - 'a']++;
        }

        for(char ch: order.toCharArray()){
            int cnt = freq[ch - 'a'];
            while(cnt-- > 0){
                sb.append(ch);
            }
        }


        return sb.toString();
        
    }
}