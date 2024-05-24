class Solution {
public:
    
    //check if freq of every char is same in two count vectors
    bool isSame(vector<int> s1Count,vector<int> s2Count){
        for(int i=0; i<26;i++){
            if(s1Count[i] != s2Count[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        // when size of s2 is less than s1 then it can't contain permutation of s1
        if(n < m)
            return false;
        
        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);
        
        //find the freq of first m char in both s1 and s2
        for(int i=0; i<m;i++){
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;            
        }
        
        //check if freq of char of s1 is same as in s2 for current window of size m
        if(isSame(s1Count,s2Count))
            return true;
        
        //check for other windows of s2
        for(int i=m;i<n;i++){
            // remove the leftmost char of prev window so decrease the char count
            s2Count[s2[i-m] - 'a']--; 
            // add the current char to the window so increase the char count
            s2Count[s2[i] - 'a']++; 
            if(isSame(s1Count,s2Count)) // check if two vector freq matches
                return true;
        }
        return false;
    }
};