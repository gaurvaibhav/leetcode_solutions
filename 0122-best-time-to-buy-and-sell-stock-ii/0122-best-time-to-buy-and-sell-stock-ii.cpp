#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        op;
        int n = prices.size();
        int forwardBuy,forwardNotbuy,currentBuy,currentNotbuy;
        forwardNotbuy = forwardBuy = 0 ;
        for(int i=n-1;i>=0; --i) {
			currentBuy = max(-prices[i]+forwardNotbuy,forwardBuy);
			currentNotbuy = max(prices[i]+forwardBuy,forwardNotbuy);
            forwardBuy = currentBuy;
			forwardNotbuy = currentNotbuy;
        }
        return forwardBuy;
    }
};