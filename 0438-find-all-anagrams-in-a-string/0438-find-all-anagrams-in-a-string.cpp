class Solution {
public:

    // Note: make sure delete entry from text hashmap when it's val = 0
    // otherwise it would create issue when comparing two maps
    // as their size would not be same
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;
        unordered_map<char, int> pat;
        for(char ch: p)
            pat[ch]++;
        
        unordered_map<char, int> text;

        int left = 0, right =  0;
        while(right < s.size()){

            text[s[right]]++;

            while(right - left + 1 > p.size()){
                text[s[left]]--;
                if(text[s[left]] == 0)
                    text.erase(s[left]);
                left++;
            }

            if(right - left + 1 == p.size()){
                if(pat == text)
                    ans.push_back(left);
            }

            right++;
        }

       return ans; 
    }
};