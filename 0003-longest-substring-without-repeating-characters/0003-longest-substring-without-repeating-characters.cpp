class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        unordered_map<char,int> mp;
        int ans=0;

        while(right<s.length()){
            
            //update frequency of character 
             mp[s[right]]++;

            // when map size < window size so it means repeating character 
            //so start removing character from window left 
            //i.e.. update count of character at left
            //If count of character at left is 0 so delete key from map 
            //and increment left pointer
            
            while(mp.size() < (right-left+1) ){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            //If window size  == map size so all unique character so update ans
            if(mp.size() == right-left+1){
                ans=max(ans,right-left+1);
            }
            right++;
        }
        return ans;       
    }
};