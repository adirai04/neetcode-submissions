class Solution {
    int n;
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int> (totalSum + 1, -1));

        return solve(nums, 0, 0, target, dp);
    }

    bool solve(vector<int> &nums, int sum, int idx, int target, vector<vector<int>> &dp) {
        if (idx >= nums.size()) {
            return sum == target;
        }

        if (sum > target) {
            return false;
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        bool take = solve(nums, sum + nums[idx], idx + 1, target, dp);
        bool skip = solve(nums, sum, idx + 1, target, dp);

        return dp[idx][sum] = take || skip;
    }
};
