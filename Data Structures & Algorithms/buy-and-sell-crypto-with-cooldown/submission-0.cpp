class Solution {
    int n;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));

        return solve(prices, 0, 1, dp);
    }

    int solve(vector<int> &prices, int idx, int buy, vector<vector<int>> &dp) {
        if (idx >= n) {
            return 0;
        }

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        if (buy) {
            // Buy today
            int take = -prices[idx] + solve(prices, idx + 1, 0, dp);
            
            // Skip today
            int skip = solve(prices, idx + 1, 1, dp);

            return dp[idx][buy] = max(take, skip);
        } else {
            // Sell today -> cooldown, so go to i + 2
            int take = prices[idx] + solve(prices, idx + 2, 1, dp);

            //Don't sell
            int skip = solve(prices, idx + 1, 0, dp); 

            return dp[idx][buy] = max(take, skip);
        }
    }
};