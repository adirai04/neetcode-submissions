class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> v;
        solve(nums, 0, 0, target, v);

        return ans;
    }

    void solve(vector<int> &nums, int idx, int sum, int target, vector<int> &temp) {
        if (idx >= n) {
            if (sum == target) {
                ans.push_back(temp);
            }
            return;
        }

        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        if (sum > target) {
            return ;
        }

        // take current num
        temp.push_back(nums[idx]);
        solve(nums, idx, sum + nums[idx], target, temp);

        //skip current num
        temp.pop_back();
        solve(nums, idx + 1, sum, target, temp);
    }
};
