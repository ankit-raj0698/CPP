class Solution {
public:

    void reverse(string &s, int i, int j){
        while(i < j){
            swap(s[i++], s[j--]);
        }
    }

    string reverseWords(string s) {
        string res = s;
        int i = 0, j = 0;
        while(j < res.size()){
            if(res[j] == ' '){
                reverse(res, i , j - 1);
                //cout << res << " "<< endl;
                i = j + 1;
            }
            j++;
        }
        reverse(res, i, j - 1);

        return res;
    }
};