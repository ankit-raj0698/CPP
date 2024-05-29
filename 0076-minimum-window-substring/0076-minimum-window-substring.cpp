class Solution {
public:
    string minWindow(string s, string t) {
        
        int left = 0, right = 0, minLen = INT_MAX;
        int startIndex = -1;
        unordered_map<char,int> mp;
        
        if(t.size() > s.size())
            return "";
        //count the freq of char in t
        for(char c:t){
            mp[c]++;
        }
        
        int count = mp.size();
        
        while(right < s.size()){
            //check if char is present in map, if yes then decrement the freq 
            if(mp.find(s[right]) != mp.end()){
                mp[s[right]]--;
                // when freq of the char is 0, decrement the count
                if(mp[s[right]] == 0)
                    count--;
            }
            
                while(count == 0){           
                    if(right - left + 1 < minLen){
                        startIndex = left;
                        minLen = right - left + 1;
                    }
                    
                    // if s[left] is in map, then increment the freq of char in map
                    if(mp.find(s[left]) != mp.end()){
                        mp[s[left]]++;
                        if(mp[s[left]] > 0)
                            count++;
                    }
                    left++; // slide the window 
                } 
            right++;
            }
        
        if(startIndex == -1)
            return "";
        else{
            return s.substr(startIndex,minLen);
        }   
    }
};