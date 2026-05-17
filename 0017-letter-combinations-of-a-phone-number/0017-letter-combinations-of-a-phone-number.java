class Solution {
    public List<String> letterCombinations(String digits) {
        String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> ans = new ArrayList<>();
        solve(digits, 0, map, new StringBuilder(), ans);
        return ans;
    }

    public void solve(String digits, int start, String[] map, StringBuilder temp, List<String> ans){

        if(start >= digits.length()){
            ans.add(temp.toString());
            return;
        }

            String str = map[digits.charAt(start) - '0'];

            for(int j = 0; j < str.length(); j++){
                temp.append(str.charAt(j));
                solve(digits, start + 1, map, temp, ans);
                temp.deleteCharAt(temp.length() - 1);
            
        }
    }
}