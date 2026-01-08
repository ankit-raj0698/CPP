class Solution {

    boolean isAlNum(char ch){
        return ((ch >= 'a' && ch <= 'z') 
        || (ch >= 'A' && ch <= 'Z') 
        || (ch >= '0' && ch <= '9'));
    }

    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        int i = 0, j = s.length() - 1;
        while(i < j){
            
            while(i < j && !isAlNum(s.charAt(i)))
                i++;
            while(i < j && !isAlNum(s.charAt(j)))
                j--;
            if(Character.toLowerCase(s.charAt(i++)) != Character.toLowerCase(s.charAt(j--)))
                return false;
        }
        return true;
    }
}