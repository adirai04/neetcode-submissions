class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> freq;
        for (char ch : t) {
            freq[ch]++;
        }

        int len = INT_MAX;
        int startPt = 0;

        int countReq = t.size();
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] > 0) {
                countReq--;
            }

            freq[s[i]]--;

            while (countReq == 0) {
                if ((i - left + 1) < len) {
                    len = i - left + 1;
                    startPt = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0) countReq++;

                left++;
            }
        }

        if (len == INT_MAX) {
            return "";
        }

        return s.substr(startPt, len);
    }
};
