class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        solve(s, 0, new ArrayList<>(), ans);
        return ans;   
    }

    public boolean isPalindrome(String s){
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public void solve(String s, int start, List<String> temp, List<List<String>> ans){

        if(start >= s.length()){
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i = start; i < s.length(); i++){
            String subStr = s.substring(start, i + 1);
            if(isPalindrome(subStr)){
                temp.add(subStr);
                solve(s, i + 1, temp, ans);
                temp.remove(temp.size() - 1);
            }
        }
    }
}