class Solution {
public:
    int minOperations(string s) {

        int startWithZero = 0; // 010101
        int startWithOne; //  101010
        for(int i = 0; i < s.length(); i++){
            if(i % 2 == 0){
                if(s[i] == '1')
                    startWithZero++;
            }
            else{
                if(s[i] == '0')
                    startWithZero++;
            }
        }
        startWithOne = s.size() - startWithZero;
        return min(startWithOne, startWithZero);
        
    }
};