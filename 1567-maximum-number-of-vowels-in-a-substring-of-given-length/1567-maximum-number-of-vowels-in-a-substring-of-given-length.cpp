class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {

        int left = 0 , right = 0, vowelCount = 0;
        int ans = 0;
        while(right < s.size()){
            char ch = s[right];
            if(isVowel(ch))
                vowelCount++;
            
            while(right - left + 1 > k){
                if(isVowel(s[left]))
                    vowelCount--;
                left++;
            }

            if(right - left + 1 == k)
                ans = max(ans, vowelCount);
            
            right++;               
        }
       return ans; 
    }
};