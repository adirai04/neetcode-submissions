class Solution {
    int m, n;

public:
    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();

        if (n > m) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(s, t, 0, 0, dp);
    }

    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j >= n) return 1;

        if (i >= m) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        /*
        Yaad rakhne ka shortcut:
            s[i] == t[j] → Take OR Skip → a + b
            s[i] != t[j] → Only Skip → i+1, j
        */

        if (s[i] == t[j]) {
            int a = solve(s, t, i + 1, j + 1, dp);
            int b = solve(s, t, i + 1, j, dp);

            return dp[i][j] = a + b;
        } else {
            return dp[i][j] = solve(s, t, i + 1, j, dp);
        }
    }
};