class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0;
        int ans = 0;

        int maxFreq = 0;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            maxFreq = max(maxFreq, freq[s[i]]);

            int windowSize = i - left + 1;
            while ((windowSize - maxFreq) > k) {
                freq[s[left]]--;
                left++;

                windowSize = i - left + 1;
            }

            ans = max(ans, windowSize);
        }

        return ans;
    }
};
