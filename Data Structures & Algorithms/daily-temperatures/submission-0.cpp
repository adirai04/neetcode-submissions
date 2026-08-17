class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> stac;
        for (int i = n - 1; i >= 0; i--) {
            if (stac.empty()) {
                ans[i] = 0;
                stac.push(i);
            } else {
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
        }

        return ans;
    }
};
