class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        int i = 0, j = 0;
        
        while( i < s.size()){
            if(s[i] != '#')
                s1.push(s[i]); 
            else if(!s1.empty())
                s1.pop();
            i++;
        }

        while(j < t.size()){
            if(t[j] != '#')
                s2.push(t[j]); 
            else if(!s2.empty())
                s2.pop();
            j++;
        }

        if(s1 == s2)
            return true;
        
        return false;
        
    }
};