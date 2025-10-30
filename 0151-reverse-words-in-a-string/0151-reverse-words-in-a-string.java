class Solution {
    public String reverseWords(String s) {
        int startInd = s.length() - 1;
        StringBuilder ans = new StringBuilder();
        while(startInd >= 0){
            // skip trailing spaces
            while(startInd >= 0 && s.charAt(startInd) == ' ')
                startInd--;
            
            //when we have seen all characters
            if(startInd < 0)
                break;

            int endInd = startInd;
            // find space
            while(startInd >= 0 && s.charAt(startInd) != ' ')
                startInd--;
            //Actual word is present between startInd + 1 and endInd
            if(ans.isEmpty())
                ans.append(s.substring(startInd + 1, endInd + 1));
            else{
                ans.append(" ");
                ans.append(s.substring(startInd + 1, endInd + 1));
            }
            startInd--;
        }
        return ans.toString();
    }
}