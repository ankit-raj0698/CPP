class Solution {
    public boolean isPalindrome(String s) {
        String str = s.toLowerCase();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            if((ch >= 'a' && ch <= 'z')
            || (ch >= 'A' && ch <= 'Z')
            || (ch >= '0' && ch <= '9'))
                sb.append(ch);
        }
        int i = 0, j = sb.length() - 1;
        while(i < j){
            if(sb.charAt(i++) != sb.charAt(j--))
                return false;
        }
        return true;
    }
}