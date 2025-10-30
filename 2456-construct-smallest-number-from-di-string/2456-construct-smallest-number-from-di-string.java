class Solution {
    public String smallestNumber(String pattern) {
        Deque<Integer> st = new ArrayDeque<>();
        StringBuilder ans = new StringBuilder();
        int cnt = 0;
        for(int i = 0; i <= pattern.length(); i++){
            cnt++;
            if(i == pattern.length() || pattern.charAt(i) == 'I'){
                ans.append(cnt);
                while(!st.isEmpty()){
                    ans.append(st.pop());
                }
            }
            else{
                st.push(cnt);
            }
        }
        return ans.toString();
    }
}