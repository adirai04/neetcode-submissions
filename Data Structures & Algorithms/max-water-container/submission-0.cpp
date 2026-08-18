class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j) {
            int ht = min(height[i], height[j]);
            int wt = j - i;
            int area = ht * wt;

            ans = max(area, ans);

            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};
