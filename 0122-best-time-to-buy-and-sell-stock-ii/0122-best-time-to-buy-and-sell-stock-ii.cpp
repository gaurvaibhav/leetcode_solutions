#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        op;
        int n = prices.size();
        vector<int> forward(2,0), curr(2,0);
        forward[0] = forward[1] = 0 ;
        for(int i=n-1;i>=0; --i) {
            for(int j=0; j<=1; ++j) {
                int profit = 0 ;
                if(j) 
                    profit = max(-prices[i]+forward[0],forward[1]);
                else 
                    profit = max(prices[i]+forward[1],forward[0]);
                curr[j] = profit;
            }
            forward = curr;
        }
        return forward[1];
    }
};