class Solution {
    unordered_set<string> st;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        st.insert(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);

        return solve(s, 0, dp);
    }

    bool solve(string &s, int idx, vector<int> &dp) {
        if (s.empty()) return true;

        if (dp[idx] != -1) return dp[idx];

        string curr = "";
        for (int i = 0; i < s.size(); i++) {
            curr += s[i];
            if (st.find(curr) == st.end()) continue;

            string remain = s.substr(i + 1);
            if (solve(remain, idx + i, dp)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
};
