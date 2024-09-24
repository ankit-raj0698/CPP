class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        // use set to store all the deadends
        unordered_set<string> st(deadends.begin(), deadends.end());

        string start = "0000";
        if(st.find(start) != st.end())
            return -1;
        
        queue<string> q;
        q.push(start);
        st.insert(start);

        int level = 0;

        while(!q.empty()){
            int n = q.size();

            // perform level order traversal
            while(n--){
                string curr = q.front();
                q.pop();

                // when curr string is target
                if(curr == target)
                    return level;

                // try all possiblities on each char of string
                // increasing and decreasing the char for each index
                for(int i = 0; i < 4; i++){
                    char ch = curr[i];

                    // increase the char val
                    curr[i] = ch == '9'? '0' : ch + 1;
                    // when increased char is not in deadend, push in queue and set
                    if(st.find(curr) == st.end()){
                        st.insert(curr);
                        q.push(curr);
                    }
                    // revert to original string and the decrease the char val
                    curr[i] = ch;
                    curr[i] = ch == '0'? '9' : ch - 1;
                    // when decreased char is not in deadend, push in queue and set
                    if(st.find(curr) == st.end()){
                        st.insert(curr);
                        q.push(curr);
                    }
                    // in the end revert to original string
                    curr[i] = ch;
                }
            }
            level++;
        }
        // when target can't be reachd from start
        return -1;
    }
};