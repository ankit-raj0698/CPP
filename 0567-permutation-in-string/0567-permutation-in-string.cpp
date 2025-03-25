class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;

        vector<int> first(26,0);
        vector<int> second(26,0);

        // store freq of char of s1
        for(char ch: s1)
            first[ch - 'a']++;
        
        // k is going to be our window size
        int k = s1.size();
        
        int left = 0, right = 0;
        while(right < s2.size()){
            // store the freq of current char of s2
            second[s2[right] - 'a']++;

            // when current window size > k
            while(right - left + 1 > k){
                second[s2[left] - 'a']--;
                left++;
            }

            // when window size == k, then check freq of char of s1 and s2 till now
            if(right - left + 1 == k){
                if(first == second)
                    return true;
            }
            right++;
        }
        return false;
    }
};