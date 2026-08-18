class Solution {
    int m, n;
public:
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return solve(text1, text2, 0, 0, dp);
    }

    int solve(string &first, string &second, int i, int j, vector<vector<int>> &dp) {
        if (i >= m || j >= n) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (first[i] == second[j]) {
            return dp[i][j] = 1 + solve(first, second, i + 1, j + 1, dp);
        } else {
            int a = solve(first, second, i + 1, j, dp);
            int b = solve(first, second, i, j + 1, dp);

            return dp[i][j] = max(a,b);
        }

        return -1;
    }
};
