class Solution {
    public String reverseWords(String s) {
        String str = s.trim();
        StringBuilder newStr = new StringBuilder();
        List<String> list = new ArrayList<>();
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == ' '){
                list.add(newStr.toString());
                while(i < str.length() && str.charAt(i) == ' ')
                    i++;
                newStr.setLength(0);
            }
            newStr.append(str.charAt(i));
        }
        list.add(newStr.toString());
        Collections.reverse(list);
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < list.size(); i++){
            ans.append(list.get(i));
            if(i != list.size() - 1)
                ans.append(' ');
        }    
        return ans.toString();
    }
}