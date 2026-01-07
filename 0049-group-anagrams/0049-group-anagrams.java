class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();
        for(String str: strs){
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String key = new String(arr);
            mp.computeIfAbsent(key, k->new ArrayList<>()).add(str);
        }
        return new ArrayList<>(mp.values());
    }
}