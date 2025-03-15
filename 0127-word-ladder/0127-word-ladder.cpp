class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        st.erase(beginWord); // similar to marking the word as visited

        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word == endWord)
                return level;
            
            // change each char of word from a - z
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                // change the ith char to a - z
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;

                    // new word exists in set 
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, level + 1});
                    }
                }
                // revert the changes made in original word to continue with other char of current word
                word[i] = original;
            }
        }

        return 0;
        
    }
};