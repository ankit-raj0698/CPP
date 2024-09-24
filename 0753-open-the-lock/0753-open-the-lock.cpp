class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
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

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == target)
                    return level;

                for(int i = 0; i < 4; i++){
                    char ch = curr[i];

                    curr[i] = ch == '9'? '0' : ch + 1;
                    if(st.find(curr) == st.end()){
                        st.insert(curr);
                        q.push(curr);
                    }

                    curr[i] = ch;
                    curr[i] = ch == '0'? '9' : ch - 1;
                    if(st.find(curr) == st.end()){
                        st.insert(curr);
                        q.push(curr);
                    }

                    curr[i] = ch;
                }
            }
            level++;
        }
        return -1;
    }
};