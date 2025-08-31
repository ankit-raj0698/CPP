class Solution {
    public String largestNumber(int[] nums) {

        String[] str = new String[nums.length];
        for(int i = 0; i < nums.length; i++){
            str[i] = String.valueOf(nums[i]);
        }

        Arrays.sort(str, (a,b) -> {
            return (b+a).compareTo(a+b);
        });

        StringBuilder sb = new StringBuilder();
        for(String s: str)
            sb.append(s);
        
        if(sb.charAt(0) == '0')
            return "0";

        return sb.toString();

    }
}