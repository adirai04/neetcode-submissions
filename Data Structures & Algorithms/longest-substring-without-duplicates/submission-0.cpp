class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> lastSeen;

        int n = s.size();
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (lastSeen.find(s[i]) != lastSeen.end()) {
                left = max(left, lastSeen[s[i]] + 1);
            }

            ans = max(ans, i - left + 1);
            lastSeen[s[i]] = i;
        }

        return ans;
    }
};
