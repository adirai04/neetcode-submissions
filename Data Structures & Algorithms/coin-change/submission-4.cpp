class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long> (amount + 1, -1));

        long ans = solve(coins, 0, amount, 0, dp);

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }

    long solve(vector<int> &coins, long sum, int amount, int idx, vector<vector<long>> &dp) {
        if (sum == amount) {
            return 0;
        }

        if (sum > amount) {
            return INT_MAX;
        }

        if (idx >= coins.size()) {
            if (sum == amount) {
                return 0;
            } else {
                return INT_MAX;
            }
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        // include current coin
        long take = 1 + solve(coins, sum + coins[idx], amount, idx, dp);

        // exclude current coin
        long skip = solve(coins, sum, amount, idx + 1, dp);

        return dp[idx][sum] = min(take, skip);
    }
};