class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> ss;
        unordered_map<char, int> tt;

        for (int i = 0; i < s.size(); i++) {
            ss[s[i]]++;
            tt[t[i]]++;
        }

        return ss == tt;
    }
};
