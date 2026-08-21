class Solution {
    int n;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        unordered_map<string, int> dp;

        return solve(nums, 0, 0, target, dp);
    }

    int solve(vector<int> &nums, int idx, int sum, int target, unordered_map<string, int> &dp) {
        if (idx >= n) {
            return sum == target;
        }

        string key = to_string(sum) + "$" + to_string(idx);

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int a = solve(nums, idx + 1, sum + nums[idx], target, dp);
        int b = solve(nums, idx + 1, sum - nums[idx], target, dp);

        return dp[key] = a + b;
    }
};
