class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        if (n == 1 || nums[0] < nums[n-1]) return nums[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1]) return nums[mid];
            else if (mid < n - 1 && nums[mid] > nums[mid + 1]) return nums[mid + 1];

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

    }
};
