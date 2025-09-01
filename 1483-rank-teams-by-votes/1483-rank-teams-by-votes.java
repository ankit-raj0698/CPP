class Solution {
    public String rankTeams(String[] votes) {
        int n = votes[0].length();
        Map<Character, int[]> map = new HashMap<>();

        // store the freq of each char at each position
        for(String vote: votes){
            
            for(int i = 0; i < n; i++){
                char ch = vote.charAt(i);
                if(!map.containsKey(ch))
                    map.put(ch, new int[n]);
                map.get(ch)[i]++;
            }
        }

        // sort the keys using the integer array
        List<Character> list = new ArrayList<>(map.keySet());
        Collections.sort(list, (a, b) -> {
            for(int i = 0; i < n; i++){
                if(map.get(a)[i] != map.get(b)[i])
                    return map.get(b)[i] - map.get(a)[i];
            }
             return a - b;
        });

        StringBuilder res = new StringBuilder();
        for(char ch: list)
            res.append(ch);

        return res.toString();
    }
}