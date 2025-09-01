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
        Collections.sort(list, (A, B) -> {
            for(int i = 0; i < n; i++){
                if(map.get(A)[i] != map.get(B)[i])
                    return map.get(B)[i] - map.get(A)[i];
            }
            // ties at all the postion then sort alphabetically
            return A - B;
        });

        StringBuilder res = new StringBuilder();
        for(char ch: list)
            res.append(ch);

        return res.toString();
    }
}