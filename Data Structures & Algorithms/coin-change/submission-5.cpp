class Solution {
    int n;
public:
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<long>> dp(n, vector<long> (amount + 1, -1));

        long ans = solve(coins, 0, 0, amount, dp);
        if (ans == INT_MAX) return -1;
        else return ans;
    }

    long solve(vector<int> &coins, int i, long sum, int amount, vector<vector<long>> &dp) {
        if (sum == amount) return 0;
        if (sum > amount) return INT_MAX;

        if (i >= n) {
            if (sum == amount) return 0;
            else return INT_MAX;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        long take = 1 + solve(coins, i, sum + coins[i], amount, dp);
        long skip = solve(coins, i + 1, sum, amount, dp);

        return dp[i][sum] = min(take, skip);
    }
};
