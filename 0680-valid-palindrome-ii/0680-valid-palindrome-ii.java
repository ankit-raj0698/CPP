class Solution {

    public boolean isPalindrome(String s){
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(s.charAt(left) != s.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }

    public boolean validPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        if(isPalindrome(s))
            return true;

        while(left < right){
            if(s.charAt(left) != s.charAt(right)){
                return isPalindrome(s.substring(0,left) + s.substring(left + 1)) ||
                        isPalindrome(s.substring(0, right) + s.substring(right + 1));
            }
            left++;
            right--;
        }
        return true;
    }
}