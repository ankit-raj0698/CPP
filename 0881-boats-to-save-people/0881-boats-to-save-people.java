class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int n = people.length, left = 0, right = n -1, ans = 0;
        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                left++;
                right--;
            }
            else{
                right--;
            }
            ans++;   
        }
        return ans;
    }
}