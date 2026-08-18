class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int cp  = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - cp;
            ans = max(ans, profit);

            cp = min(cp, prices[i]);
        }

        return ans;
    }
};
