class Solution {
public:
    bool matches(string num, string pattern){
        for(int i = 0; i < pattern.size(); i++){
            if((pattern[i] == 'I' && num[i] > num[i+1]) || (pattern[i] == 'D' && num[i] < num[i+1]))
                return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        string str = "";
        for(int i = 1; i <= pattern.size() + 1; i++)
            str.push_back(i+'0');
            
        while(!matches(str,pattern)){
            next_permutation(str.begin(), str.end());
        }

        return str;
    }
};