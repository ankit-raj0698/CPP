class Solution {
    public String reverseWords(String s) {
        String str = s.trim();
        String newStr = "";
        List<String> list = new ArrayList<>();
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == ' '){
                list.add(newStr.trim());
                while(str.charAt(i) == ' ')
                    i++;
                newStr = "";
            }
            newStr += str.charAt(i);
        }
        list.add(newStr);
        System.out.println(list);
        Collections.reverse(list);
        String ans = "";
        for(int i = 0; i < list.size(); i++)
            ans += list.get(i) + " ";
        
        return ans.trim();
    }
}