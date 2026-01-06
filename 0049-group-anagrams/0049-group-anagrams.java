class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();
        List<List<String>> ans = new ArrayList<>();
        for(String str: strs){
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);

            if(!mp.containsKey(key))
                mp.put(key, new ArrayList<>());
            mp.get(key).add(str);
        }

        // for(Map.Entry<String, List<String>> entry: mp.entrySet()){
        //     ans.add(entry.getValue());
        // }
        // return ans;
        return new ArrayList<>(mp.values());
    }
}