class Solution {
public:
    
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int maxFreqCount = 0;
        int length = 0;
        
        int left = 0, right =0;
        
        while(right < s.size()){
            count[s[right] - 'A']++;
            maxFreqCount = max(maxFreqCount,count[s[right] - 'A']);
            
            //LOGIC : when windowsize - maxFreqCount <= k then calculate result
            // otherwise update the left pointer to shrink window
            while( (right - left + 1) - maxFreqCount > k){
                count[s[left] - 'A']--;
                left++;
            }
            length = max(length, (right - left + 1));
            right++;
        }
        return length;
    }
};