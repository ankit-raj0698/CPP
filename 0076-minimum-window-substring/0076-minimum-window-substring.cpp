class Solution {
public:
    string minWindow(string s, string t) {
        string ans  = "";
        unordered_map<char,int> mp;
        
        if(t.size() > s.size())
            return ans;
        
        for(auto ele:t){
            mp[ele]++;
        }
        
        int count = mp.size();
        int left = 0, right = 0;
        int minlen = INT_MAX,  leftindex = -1;
        
        while(right < s.size()){
            if(mp.find(s[right]) != mp.end()){
                mp[s[right]]--;
                if(mp[s[right]] == 0)
                    count--;
            }
            
            
            while(count == 0){
                if(right - left + 1 < minlen){
                    leftindex = left;
                    minlen = right - left + 1;
                }
                
                if(mp.find(s[left]) != mp.end()){
                    mp[s[left]]++;
                    if(mp[s[left]] == 1)
                        count++;
                } 
                left++;
            }
          right++;  
        }
        if(leftindex == -1)
            return "";
        else{
            return s.substr(leftindex,minlen);
        } 
    }
};