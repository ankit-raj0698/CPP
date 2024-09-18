class Solution {
public:
    int strStr(string haystack, string needle) {

        int index = haystack.find(needle, 0);

        if(index != haystack.size())
            return index;
        
        return -1;
        
    }
};