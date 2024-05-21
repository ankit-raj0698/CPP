class Solution {
public:
    /*
    use two pointer approach to solve this problem i=leftmost index and j=rightmost index
    use a while loop till "i<j"
    use another while loop to increment "i" till you don't encounter an alphanumeric character
    use another while loop to decrement "j" till you don't encounter an alphanumeric character
    our i and j are now pointing to alphanumeric character so compare them by converting them to lower
    case first
    if there is mismatch return false;
    */
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.size()-1;
        
        while(i < j){
            while(!isalnum(s[i]) && i < j){
                i++;
            }
            while(!isalnum(s[j]) && i < j){
                j--;
            }
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};