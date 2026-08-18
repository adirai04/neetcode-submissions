class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

        return solve(nums, -1, 0, dp);
    }

    int solve(vector<int> &nums, int prevIdx, int idx, vector<vector<int>> &dp) {
        if (idx >= nums.size()) {
            return 0;
        }

        if (dp[prevIdx + 1][idx] != -1) return dp[prevIdx + 1][idx];

        // take current number in sequence
        int take = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            take = 1 + solve(nums, idx, idx + 1, dp);
        }

        // skip current number in sequence
        int skip = solve(nums, prevIdx, idx + 1, dp);

        return dp[prevIdx + 1][idx] = max(take, skip);
    }
};
