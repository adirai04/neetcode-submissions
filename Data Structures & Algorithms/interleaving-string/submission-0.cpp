class Solution {
    int m, n, N;
public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();
        N = s3.size();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));

        return solve(s1, s2, s3, 0, 0, dp);
    }

    bool solve(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp) {
        int k = i + j;

        if (i >= m && j >= n && k >= N) {
            return true;
        }

        if (k >= N) {
            return false;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool a = false, b = false;

        if (s1[i] == s3[k]) {
            a = solve(s1, s2, s3, i + 1, j, dp);
        }

        if (s2[j] == s3[k]) {
            b = solve(s1, s2, s3, i, j + 1, dp);
        }

        return dp[i][j] = a || b;
    }
};