class Solution {
    int n;
public:
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();

        vector<int> NSE_idx = nextSmallerElement(heights);
        vector<int> PSE_idx = prevSmallerElement(heights);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int wt = NSE_idx[i] - PSE_idx[i] - 1;
            int ht = heights[i];

            int maxArea = ht * wt;

            ans = max(ans, maxArea);
        }

        return ans;
    }

    vector<int> nextSmallerElement(vector<int>& heights) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& heights) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }
};
