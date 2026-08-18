class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);

        int a = solve(nums, 0, n - 1, dp1);
        int b = solve(nums, 1, n, dp2);

        return max(a, b);
    }

    int solve(vector<int> &nums, int i, int N, vector<int> &dp) {
        if (i >= N) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        int take = nums[i] + solve(nums, i + 2, N, dp);
        int skip = solve(nums, i + 1, N, dp);

        return dp[i] = max(take, skip);
    }
};
