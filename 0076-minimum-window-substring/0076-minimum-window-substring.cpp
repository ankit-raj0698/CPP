class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> need(256,0);
        vector<int> have(256,0);
        
        int n=t.length();
        
        //store frequency of char of t
        for(auto ch:t){
            need[ch]++;
        }
        
        int left=0;
        int right=0;
        int len=INT_MAX;
        int start=-1;
        
        int count=0;
        
        while(right<s.length()){
            have[s[right]]++;
            
            if(have[s[right]]<=need[s[right]]){
                count++;
            }
            
            
            
            if(count==n){
                
                while(need[s[left]]==0 || have[s[left]]>need[s[left]]){
                    
                    if(have[s[left]]>need[s[left]]){
                        have[s[left]]--;
                    }
                    left++;
                }
                
                if(right-left+1 < len){
                    len=right-left+1;
                    start=left;
                }
                            
                
            }
            right++;
        }
        
        if(start==-1){
            return "";
        }
        else{
            return s.substr(start,len);
        }
               
    }
};