class Solution {
    int m, n;
public:
    int minDistance(string first, string second) {
        m = first.size();
        n = second.size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return solve(first, second, 0, 0, dp);
    }

    int solve(string &first, string &second, int i, int j, vector<vector<int>> &dp) {
        if (i >= m) return n - j;
        if (j >= n) return m - i;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (first[i] == second[j]) {
            return dp[i][j] = solve(first, second, i + 1, j + 1, dp);
        }

        int a = 1 + solve(first, second, i + 1, j + 1, dp);
        int b = 1 + solve(first, second, i + 1, j, dp);
        int c = 1 + solve(first, second, i, j + 1, dp);

        return dp[i][j] = min({a, b, c});
    }
};
