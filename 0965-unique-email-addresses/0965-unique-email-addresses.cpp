class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmail;
        for(int i = 0; i < emails.size(); i++){
            string key = "";
            for(int j = 0; j < emails[i].size(); j++){
                // handles . in the local part
                if(emails[i][j] == '.')
                    continue;

                // take everything after @ as it is by using substring
                else if(emails[i][j] == '@'){
                    key += emails[i].substr(j);
                    break;
                }

                // when encounter + , skip all char till you reach @
                // then take everything after @ as it is by using substring
                else if(emails[i][j] == '+'){

                    while(emails[i][j] != '@')
                        j++;
                    // now j is at @ so find substring and append it to key    
                    key += emails[i].substr(j);
                    break;
                }
                // when processing normal char
                key += emails[i][j];
            }
            if(!key.empty())
                uniqueEmail.insert(key);
        }
        
        return uniqueEmail.size();
    }
};