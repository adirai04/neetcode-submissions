class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int leftProd = 1;
        int rightProd = 1;

        for (int i = 0; i < n; i++) {
            leftProd *= nums[i];
            rightProd *= nums[n - i - 1];

            ans = max({ans, leftProd, rightProd});

            if (leftProd == 0) leftProd = 1;
            if (rightProd == 0) rightProd = 1;
        }

        return ans;
    }
};
