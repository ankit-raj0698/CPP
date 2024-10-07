class Trie {
public:
    struct trieNode{
        bool isEndofWord;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEndofWord = false;
        for(int i = 0; i < 26; i++)
            newNode->children[i] = nullptr;
        
        return newNode;
    }

    trieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* curr = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int ind = ch - 'a';

            if(curr->children[ind] == nullptr){
                curr->children[ind] = getNode();
            }
              curr = curr->children[ind];  
        }
        curr->isEndofWord = true;
    }
    
    bool search(string word) {

        trieNode* curr = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int ind = ch - 'a';

            if(curr->children[ind] == nullptr){
                return false;
            }
              curr = curr->children[ind];  
        }
        
        if(curr && curr->isEndofWord == true)
            return true;
        
        return false;       
    }
    
    bool startsWith(string prefix) {
        trieNode* curr = root;
        int i = 0;
        for(; i < prefix.length(); i++){
            char ch = prefix[i];
            int ind = ch - 'a';

            if(curr->children[ind] == nullptr){
                return false;
            }
              curr = curr->children[ind];  
        }
        
        if(i == prefix.length())
            return true;
        
        return false; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */