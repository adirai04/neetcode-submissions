class Solution {
    int n;
public:
    int numDecodings(string s) {
        n = s.size();
        vector<int> dp(n, -1);

        return solve(s, 0, dp);
    }

    int solve(string &s, int idx, vector<int> &dp) {
        if (idx >= n) return 1;

        if (s[idx] == '0') return 0;

        if (dp[idx] != -1) return dp[idx];

        // take one digit
        int oneDigit = solve(s, idx + 1, dp);

        // take two digit
        int twoDigit = 0;
        if (idx < n - 1) {
            int d1 = s[idx] - '0';
            int d2 = s[idx + 1] - '0';

            int num = d1 * 10 + d2;

            if (num <= 26) {
                twoDigit = solve(s, idx + 2, dp);
            }
        }

        return dp[idx] = oneDigit + twoDigit;
    } 
};
