class Solution {
    int n;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int a = solve(cost, 0, dp1);
        int b = solve(cost, 1, dp2);

        return min(a, b);
    }

    int solve(vector<int> &cost, int idx, vector<int> &dp) {
        if (idx >= n) return 0;

        if (dp[idx] != -1) return dp[idx];

        int oneStep = cost[idx] + solve(cost, idx + 1, dp);
        int twoStep = cost[idx] + solve(cost, idx + 2, dp);

        return dp[idx] = min(oneStep, twoStep);
    }
};
