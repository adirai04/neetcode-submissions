class Solution {
    int n;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int> dp(n, -1);

        return solve(days, costs, 0, dp);
    }

    int solve(vector<int> &days, vector<int> &costs, int idx, vector<int> &dp) {
        if (idx >= n) return 0;

        if (dp[idx] != -1) return dp[idx];

        int a = costs[0] + solve(days, costs, idx + 1, dp);

        int i = idx;
        while (i < n && days[i] < days[idx] + 7) {
            i++;
        }
        int b = costs[1] + solve(days, costs, i, dp);

        i = idx;
        while (i < n && days[i] < days[idx] + 30) {
            i++;
        } 
        int c = costs[2] + solve(days, costs, i, dp);

        return dp[idx] = min({a, b, c});
    }
};