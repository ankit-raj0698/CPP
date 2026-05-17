class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        solve(n, 0, 0, new StringBuilder(), ans);
        return ans;
    }

    public void solve(int n, int open, int close, StringBuilder sb, List<String> ans){

        if(sb.length() == 2*n){
            ans.add(sb.toString());
            return;
        }

        if(open < n){
            sb.append('(');
            solve(n, open + 1, close, sb, ans);
            sb.deleteCharAt(sb.length() - 1);
        }

        if(close < open){
            sb.append(')');
            solve(n, open, close + 1, sb, ans);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}