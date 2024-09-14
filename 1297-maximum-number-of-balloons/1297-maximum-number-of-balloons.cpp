class Solution {
public:

    bool isValid(char ch){
        if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n')
            return true;
        return false;
    }
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> balloon;
        unordered_map<char, int> count;
        int res = text.size();
        string str = "balloon";

        for(char ch: str)
            balloon[ch]++;

        for(char ch: text){
            if(isValid(ch))
                count[ch]++;
        }

        if(count.size() < balloon.size())
            return 0;
        
        for(auto [key,value]: balloon){
            res = min(res, count[key]/value);
        }
        return res;
    }
};