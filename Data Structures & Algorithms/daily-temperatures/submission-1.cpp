class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<int> stac;

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stac.empty() && arr[stac.top()] <= arr[i]) {
                stac.pop();
            }

            if (stac.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = stac.top() - i;
            }

            stac.push(i);
        }

        return ans;
    }
};