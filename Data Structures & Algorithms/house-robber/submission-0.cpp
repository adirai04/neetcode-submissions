class Solution {
    int n;
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);

        return solve(nums, 0, dp);
    }

    int solve(vector<int> &nums, int idx, vector<int> &dp) {
        if (idx >= n) return 0;

        if (dp[idx] != -1) return dp[idx];

        // take current house
        int take = nums[idx] + solve(nums, idx + 2, dp);

        // skip current house
        int skip = solve(nums, idx + 1, dp);

        return dp[idx] = max(take, skip);
    }
};
