class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int prod = 1;

        int zeroes = 0;
        for (int num : nums) {
            if (num == 0) {
                zeroes++;
            } else {
                prod = prod * num;
            }

            if (zeroes > 1) return ans;

        }

        for (int i = 0; i < n; i++) {
            if (zeroes) {
                if (nums[i] == 0) {
                    ans[i] = prod;
                }
            } else {
                ans[i] = prod / nums[i];
            }
        }

        return ans;
    }
};
