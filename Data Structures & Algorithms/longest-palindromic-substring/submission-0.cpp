class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int maxLen = 0;
        int startPt = 0;

        vector<vector<int>> dp(n, vector<int> (n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j, dp)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        startPt = i;
                    }
                }
            }
        }

        return s.substr(startPt, maxLen);
    }

    bool isPalindrome(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
        } else {
            return dp[i][j] = false;
        }
    }
};
