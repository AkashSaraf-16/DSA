class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 1) return 0;
        int minPrice = INT_MAX;
        int maxProfit_global = 0;
        for (int i = 0; i < size; i++) {
            minPrice = min(prices[i],minPrice);
            maxProfit_global = max(maxProfit_global, prices[i] - minPrice);           
        }
        return maxProfit_global;
        
    }
};