class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    
    TrieNode() {
        isEnd=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        int len=word.length();
        int index=0;
        TrieNode *curr=root;
        for(int i=0;i<len;i++){
            index=word[i]-'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();
            curr=curr->child[index];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        int len=word.length();
        int index=0;
        for(int i=0;i<len;i++){
            index=word[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr=curr->child[index];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        int len=prefix.length();
        int index=0;
        for(int i=0;i<len;i++){
            index=prefix[i]-'a';
            curr=curr->child[index];
            if(curr==NULL)
                return false;
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */