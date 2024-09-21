class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int left = 0, right = 0, ans = 0, sum = 0;

        while(right < arr.size()){

            sum += arr[right];

            while(right - left + 1 > k){
                sum -= arr[left];
                left++;
            }
            
            if((right - left + 1 == k) && (sum / k) >= threshold)
                ans++;
            
            right++;
        }
        return ans;
    }
};