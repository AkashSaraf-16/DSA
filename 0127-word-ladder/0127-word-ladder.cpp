class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // to check whether we have word in list in O(1) time
        unordered_set<string> s(wordList.begin(),wordList.end());
        // If endword is not present in dictionary return 0
        if(s.find(endWord)==s.end())
            return 0;
        // we will use queue to do BFS kind traversal
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int changes=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string word=q.front();
                q.pop();
                if(endWord==word)
                    return changes;
                for(int j=0;j<word.length();j++){
                    char c=word[j];
                    for(int k='a';k<='z';k++){
                        word[j]=k;
                        if(s.find(word)!=s.end() && visited.find(word)==visited.end()){
                            q.push(word);
                            visited.insert(word);
                        }
                        word[j]=c;
                    }
                }  
            }
            ++changes;
        }
        return 0;
        
    }
};