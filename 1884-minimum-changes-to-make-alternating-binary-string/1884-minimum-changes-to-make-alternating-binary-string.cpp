class Solution {
public:
    int minOperations(string s) {

        int startWithZero = 0; // 010101
        int startWithOne = 0; //  101010
        for(int i = 0; i < s.length(); i++){
            if(i % 2 == 0){
                if(s[i] == '0')
                    startWithOne++;
                else 
                    startWithZero++;
            }
            else{
                if(s[i] == '0')
                    startWithZero++;
                else
                    startWithOne++;
            }
        }

        return min(startWithOne, startWithZero);
        
    }
};