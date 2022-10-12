class Solution {
public:
// N: max no. of emails in a account M: total account then TC: O(NMLogMN) SC:O(NM)
    unordered_map<string,vector<string>> adjList;       // adjacency list
    unordered_set<string> visited;
    void DFS(vector<string> &mergedAccount, string email){
        visited.insert(email);      // marking the email as visited so as to keep track
        mergedAccount.push_back(email);
        for(string &adjacent:adjList[email]){
            if(visited.find(adjacent)==visited.end()){      // if the adjacent email is also not visited than we will do DFS to get all those adjacent email which belong to that email  
                DFS(mergedAccount,adjacent);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Step 1: Create the adjacency list(undirected) of only emails
        for(vector<string> &account : accounts){
            string firstEmail=account[1];
            for(int i=2;i<account.size();i++){
                adjList[firstEmail].push_back(account[i]);
                adjList[account[i]].push_back(firstEmail);
            }
        }
        vector<vector<string>> mergedAccounts;
        for(vector<string> &account:accounts){
            string name=account[0];
            string firstEmail=account[1];
            // if this email is not visited already then it means this account is separate and we can go on to insert all the emails to this account
            if(visited.find(firstEmail)==visited.end()){    
                vector<string> mergedAccount;
                mergedAccount.push_back(name);
                // Step 2: Do DFS(becoz in DFS we will be able to get easily the emails, the common ones also)
                DFS(mergedAccount,firstEmail);
                sort(mergedAccount.begin()+1,mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }   
        }
        return mergedAccounts;
    }
};