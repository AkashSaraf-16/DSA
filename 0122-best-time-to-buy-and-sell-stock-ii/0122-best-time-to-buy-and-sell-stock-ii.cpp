class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2,0) ,curr(2,0);
        ahead[0]=ahead[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                int profit = 0;
                if(buy){                // if we can buy
                    profit = max((-prices[ind]) + ahead[false],ahead[true]);
                          //      take(buy)               not take(not buy)
                }
                else                    // if we can sell
                    profit = max((prices[ind]) + ahead[true],ahead[false]); 
                          //      sell                    // not sell
                curr[buy]=profit;                
            }
            ahead=curr;
        }
        return ahead[1];
    }
};