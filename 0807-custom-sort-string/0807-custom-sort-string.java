class Solution {
    public String customSortString(String order, String s) {
        Map<Character,Integer> mp = new HashMap<>();
        for(int i = 0; i < order.length(); i++){
            char ch = order.charAt(i);
            mp.put(ch,i);
        }

        List<Character> list = new ArrayList<>();
        for(char ch: s.toCharArray())
            list.add(ch);

        
        Collections.sort(list, (ch1, ch2) -> {
            int rank1 = mp.getOrDefault(ch1, Integer.MAX_VALUE);
            int rank2 = mp.getOrDefault(ch2, Integer.MAX_VALUE);
            if(rank1 == rank2)
                return ch1 - ch2;
            return rank1 - rank2;
        });

        StringBuilder str = new StringBuilder();
        for(char ch: list)
            str.append(ch);

        return str.toString();
            
    }
}