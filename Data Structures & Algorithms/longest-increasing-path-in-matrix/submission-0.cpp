class Solution {
    int m, n;

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, solve(matrix, i, j, dp));
            }
        }

        return ans + 1;
    }

    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0; 
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = 0, down = 0, right = 0, left = 0;

        if ((i + 1) < m && matrix[i + 1][j] > matrix[i][j]) {
            down = 1 + solve(matrix, i + 1, j, dp);
        }

        if ((i - 1) >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            up = 1 + solve(matrix, i - 1, j, dp);
        }

        if ((j + 1) < n && matrix[i][j + 1] > matrix[i][j]) {
            right = 1 + solve(matrix, i, j + 1, dp);
        } 

        if ((j - 1) >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            left = 1 + solve(matrix, i, j - 1, dp);
        } 

        return dp[i][j] = max({up, down, right, left});
    }
};
