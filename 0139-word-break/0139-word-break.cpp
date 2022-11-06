// in this problem we need to check whether we can break a single word s into parts which results in all the parts being there in distionary given Eg: catsandog -> here we can break the word as cat|sand|og but og is not in Dist therefore not valid choice again trying cats|and|og again we cant do this hence we will return false in this case approach: using dp+trie we can approach it in a way like we will create trie for the the words in dict then we will create dp vector whose ith index represent whther the length of i string is there in dict or not by looking up in trie.
class Trie{
public:
    Trie *child[26];
    bool isEnd;
    Trie(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
class Solution {
private:
    Trie *root;
public:
    void implemntTrie(string &s){
        Trie *curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index] = new Trie();
            curr=curr->child[index];
        }
        curr->isEnd=true;
    }
    bool searchWord(string s){
        Trie *curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr=curr->child[index];
        }
        return curr->isEnd;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        root= new Trie();
        for(string &word:wordDict)
            implemntTrie(word);
        vector<bool> dp(s.length()+1,false);        // here the ith index represent whether a word of that length is there in the wordDict
        dp[0]=true;
        for(int len=1;len<=s.length();len++){       // for every len from 1-len of s
            for(int i=0;i<len;i++){                 // strating from i=0-len-1 its substrings 
                if(dp[i] && searchWord(s.substr(i,len-i)))      // we will check whether the word is berakble at index i-1 or not if yes then break it from i-len-1
                    dp[len]=true;
            }
        }
        return dp[s.length()];
    }
};