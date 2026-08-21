class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> v;
        solve(nums, 0, v);

        return ans;
    }

    void solve(vector<int> &nums, int idx, vector<int> &temp) {
        if (idx >= n) {
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);

        temp.pop_back();
        solve(nums, idx + 1, temp);
    }
};
