class Solution {
public:
    /*
    check the size of s and t, if size is not same return false
    create an unordered map and find the frequency of every element of s 
    update frequency map accordingly
    for each element of t, decrement the frequency of every element of map 
    in the end, check if there exists any value(map.second) in map which is not 0
    if yes then return false
    */
    
     bool isAnagram(string s, string t) {       
        if(s.size()!=t.size()){
            return false;
        }
        
        unordered_map<char,int> mp;    
         
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        } 
        for(int i=0;i<t.size();i++){
            mp[t[i]]--;
        }
        
        for(auto m:mp){
            if(m.second != 0){
                return false;
            }
        }
        
        return true;        
        
    }
};