class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int person = accounts.size();
        int wealth = accounts[0].size(); 
        int richest = INT_MIN;
        for (int i = 0 ; i<person ; i++)
        {
            int currperson = 0;
            for(int j =0 ; j < wealth ; j++){
                currperson += accounts[i][j];
            }
            if(currperson>richest)
                richest =currperson;            
            
        }
        return richest;
    }
};