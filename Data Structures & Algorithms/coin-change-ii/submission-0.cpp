class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(coins, 0, amount, 0, dp);
    }

    int solve(vector<int>& coins, int sum, int amount, int idx, vector<vector<int>> &dp) {
        if (sum == amount) {
            return 1;
        }

        if (sum > amount) {
            return 0;
        }

        if (idx >= coins.size()) {
            return sum == amount;
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        int take = solve(coins, sum + coins[idx], amount, idx, dp);
        int skip = solve(coins, sum, amount, idx + 1, dp);

        return dp[idx][sum] = take + skip;
    }
};