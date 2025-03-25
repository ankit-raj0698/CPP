class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        
        unordered_map<char,int> mp;
        for(char ch: t)
            mp[ch]++;
        
        int cnt = t.size(); // size of window
        int left = 0, right = 0, minlen = 1e9, start = -1;

        while(right < s.size()){
            char ch = s[right];

            // char which are present in t only those count > 0
            // so we have got 1 reqd char
            if(mp[ch] > 0)
                cnt--;
            
            mp[ch]--;


            while(cnt == 0){
                // when curr window size < min window size
                // update the window size and track from where this window is starting
                if(right - left + 1 < minlen){
                    minlen = right - left + 1;
                    start = left;
                }

                // try to shrink the current window from left side
                mp[s[left]]++;

                // only case where we get count > 0 in map
                // when this is a reqd char
                if(mp[s[left]] > 0)
                    cnt++;
                left++;
            }
            right++;
        }

        return start == -1 ? "" : s.substr(start, minlen);
    }
};