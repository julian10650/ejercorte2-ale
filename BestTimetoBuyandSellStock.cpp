class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = __INT_MAX__;
        int maxPro = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            minPrice = std::min(minPrice, prices[i]);
            maxPro = std::max(maxPro, prices[i] - minPrice);
        }
        
        return maxPro;
        
    }
};
