class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) st.insert(num);

        int ans = 0;
        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int x = num;
                int cnt = 0;

                while (st.find(x) != st.end()) {
                    x++;
                    cnt++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
